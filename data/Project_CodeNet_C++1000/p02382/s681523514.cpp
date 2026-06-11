#include <cmath>
#include <iomanip>
#include <iostream>
#include <vector>

template <class T>
T generalDistance(const std::vector<T> &lhs, const std::vector<T> &rhs,
                  const T &p) {
  T sum = 0.0;
  for (int i = 0; i < lhs.size(); i++) {
    sum += pow(abs(lhs[i] - rhs[i]), p);
  }
  return pow(sum, 1.0 / p);
}

template <class T>
T chebyshevDistance(const std::vector<T> &lhs, const std::vector<T> &rhs) {
  T max = -1.0;
  for (int i = 0; i < lhs.size(); i++) {
    T val = abs(lhs[i] - rhs[i]);
    if (val > max) max = val;
  }
  return max;
}

template <class T>
std::vector<T> getElements(int n) {
  std::vector<T> vec;
  while (n-- > 0) {
    T x;
    std::cin >> x;
    vec.push_back(x);
  }
  return vec;
}

int main() {
  int n;
  std::cin >> n;
  auto vecA = getElements<double>(n), vecB = getElements<double>(n);
  std::cout << std::fixed << std::setprecision(6);
  std::cout << generalDistance(vecA, vecB, 1.0) << std::endl;
  std::cout << generalDistance(vecA, vecB, 2.0) << std::endl;
  std::cout << generalDistance(vecA, vecB, 3.0) << std::endl;
  std::cout << chebyshevDistance(vecA, vecB) << std::endl;
  return 0;
}

