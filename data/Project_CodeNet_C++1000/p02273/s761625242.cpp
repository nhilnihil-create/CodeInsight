/**
 * http://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=ALDS1_5_C&lang=jp
 */

#include <cmath>
#include <iomanip>
#include <iostream>
#include <iterator>
#include <sstream>
#include <vector>

void printVector(const std::vector<double> &v) {
  std::ostringstream oss;
  oss << std::fixed << std::setprecision(8);
  std::copy(v.begin(), v.end() - 1, std::ostream_iterator<double>(oss, " "));
  oss << v.back();
  std::cout << oss.str() << std::endl;
}

void kochCurve(std::vector<double> &p1, std::vector<double> &p2,
               unsigned short n) {
  if (n == 0) {
    return;
  }
  const double Pi = atan((double)INFINITY) * 2;
  const double cos60 = cos(Pi * 60 / 180);
  const double sin60 = sin(Pi * 60 / 180);
  std::vector<double> s = {(2 * p1[0] + p2[0]) / 3, (2 * p1[1] + p2[1]) / 3};
  std::vector<double> t = {(p1[0] + 2 * p2[0]) / 3, (p1[1] + 2 * p2[1]) / 3};
  std::vector<double> u = {(t[0] - s[0]) * cos60 - (t[1] - s[1]) * sin60 + s[0],
                           (t[0] - s[0]) * sin60 + (t[1] - s[1]) * cos60 +
                               s[1]};
  kochCurve(p1, s, n - 1);
  printVector(s);
  kochCurve(s, u, n - 1);
  printVector(u);
  kochCurve(u, t, n - 1);
  printVector(t);
  kochCurve(t, p2, n - 1);
}

int main(int argc, char const *argv[]) {
  unsigned short n;
  std::string Param;
  std::istringstream Stream;
  getline(std::cin, Param);
  Stream.str(Param);
  Stream >> n;
  Stream.clear();
  std::vector<double> p1 = {0, 0};
  std::vector<double> p2 = {100, 0};
  printVector(p1);
  kochCurve(p1, p2, n);
  printVector(p2);

  return 0;
}