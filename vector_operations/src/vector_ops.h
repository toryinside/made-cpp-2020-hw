#pragma once
#include <iostream>
#include <vector>

namespace task {

std::vector<double> operator+(const std::vector<double> &arg) { return arg; }

std::vector<double> operator-(const std::vector<double> &arg) {
  auto answer = std::vector<double>();
  answer.reserve(arg.size());

  for (const auto &element : arg) {
    answer.push_back(-element);
  }

  return answer;
}

std::vector<double> operator+(const std::vector<double> &lhs,
                              const std::vector<double> &rhs) {
  size_t length = lhs.size();
  std::vector<double> answer;
  answer.reserve(length);

  for (size_t index = 0; index < length; ++index) {
    answer.push_back(lhs[index] + rhs[index]);
  }

  return answer;
}

std::vector<double> operator-(const std::vector<double> &lhs,
                              const std::vector<double> &rhs) {
  return lhs + (-rhs);
}

double operator*(const std::vector<double> &lhs,
                 const std::vector<double> &rhs) {
  size_t length = lhs.size();
  double answer;

  for (size_t index = 0; index < length; ++index) {
    answer += lhs[index] * rhs[index];
  }

  return answer;
}

std::vector<double> operator%(const std::vector<double> &lhs,
                              const std::vector<double> &rhs) {
  std::vector<double> answer(3, 0);
  answer[0] = lhs[1] * rhs[2] - lhs[2] * rhs[1];
  answer[1] = -lhs[0] * rhs[2] + lhs[2] * rhs[0];
  answer[2] = lhs[0] * rhs[1] - lhs[1] * rhs[0];

  return answer;
}

bool operator||(const std::vector<double> &lhs,
                const std::vector<double> &rhs) {
  bool lhs_zero = true;
  bool rhs_zero = true;
  size_t length = lhs.size();

  bool answer = true;
  double coefficient = 0.;

  for (size_t index = 0; index < length; ++index) {
    if (lhs_zero && lhs[index])
      lhs_zero = false;
    if (rhs_zero && rhs[index]) {
      rhs_zero = false;
      coefficient = lhs[index] / rhs[index];
    }
    if (!rhs_zero && fabs(lhs[index] / rhs[index] - coefficient) > 1e-2)
      answer = false;
  }

  return lhs_zero || rhs_zero || answer;
}

bool operator&&(const std::vector<double> &lhs,
                const std::vector<double> &rhs) {
  bool lhs_zero = true;
  bool rhs_zero = true;
  size_t length = lhs.size();

  bool answer = true;
  double coefficient = 0.;

  for (size_t index = 0; index < length; ++index) {
    if (lhs_zero && lhs[index])
      lhs_zero = false;
    if (rhs_zero && rhs[index]) {
      rhs_zero = false;
      coefficient = lhs[index] / rhs[index];
    }
    if (!rhs_zero && fabs(lhs[index] / rhs[index] - coefficient) > 1e-2)
      answer = false;
  }

  return lhs_zero || rhs_zero || answer && (coefficient > 0);
}

std::istream &operator>>(std::istream &in, std::vector<double> &arg) {
  size_t length;
  in >> length;

  arg = std::vector<double>(length, 0);

  for (auto &element : arg) {
    in >> element;
  }

  return in;
}

std::ostream &operator<<(std::ostream &out, const std::vector<double> &arg) {
  bool isfirst = true;
  for (const auto &element : arg) {
    if (isfirst) {
      out << element;
      isfirst = false;
    } else {
      out << " " << element;
    }
  }
  out << "\n";

  return out;
}

void reverse(std::vector<double> &arg) {
  size_t length = arg.size();

  for (size_t index = 0; index < length / 2; ++index) {
    double buffer = arg[index];
    arg[index] = arg[length - 1 - index];
    arg[length - 1 - index] = buffer;
  }
}

std::vector<int> operator|(const std::vector<int> &lhs,
                           const std::vector<int> &rhs) {
  size_t length = lhs.size();
  std::vector<int> answer;
  answer.reserve(length);

  for (size_t index = 0; index < length; ++index) {
    answer.push_back(lhs[index] | rhs[index]);
  }

  return answer;
}

std::vector<int> operator&(const std::vector<int> &lhs,
                           const std::vector<int> &rhs) {
  size_t length = lhs.size();
  std::vector<int> answer;
  answer.reserve(length);

  for (size_t index = 0; index < length; ++index) {
    answer.push_back(lhs[index] & rhs[index]);
  }

  return answer;
}

} // namespace task
