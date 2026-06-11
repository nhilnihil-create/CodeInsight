/**
 * http://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=ALDS1_5_C&lang=jp
 */

#include <cmath>
#include <iomanip>
#include <iostream>
#include <iterator>
#include <sstream>

struct Coodinate {
  double x;
  double y;
};

void printCoodinate(const Coodinate &xy) {
  std::ostringstream oss;
  oss << std::fixed << std::setprecision(8);
  oss << xy.x << " " << xy.y;
  std::cout << oss.str() << std::endl;
}

void kochCurve(Coodinate &p1, Coodinate &p2,
               unsigned short n) {
  if (n == 0) {
    return;
  }
  const double Pi = atan((double)INFINITY) * 2;
  const double COS60 = cos(Pi * 60 / 180);
  const double SIN60 = sin(Pi * 60 / 180);
  Coodinate s = {(2 * p1.x + p2.x) / 3, (2 * p1.y + p2.y) / 3};
  Coodinate t = {(p1.x + 2 * p2.x) / 3, (p1.y + 2 * p2.y) / 3};
  Coodinate u = {(t.x - s.x) * COS60 - (t.y - s.y) * SIN60 + s.x,
                           (t.x - s.x) * SIN60 + (t.y - s.y) * COS60 +
                               s.y};
  kochCurve(p1, s, n - 1);
  printCoodinate(s);
  kochCurve(s, u, n - 1);
  printCoodinate(u);
  kochCurve(u, t, n - 1);
  printCoodinate(t);
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
  Coodinate p1 = {0, 0};
  Coodinate p2 = {100, 0};
  printCoodinate(p1);
  kochCurve(p1, p2, n);
  printCoodinate(p2);

  return 0;
}