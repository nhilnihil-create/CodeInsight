#include <iostream>
#include <cmath>
#include <stdio.h>

int main() {
  static const double pi = 3.141592653589793;
  int a, b, C;
  std::cin >> a >> b >> C;
  double ang = C * pi / 180;
  double S = a * b * sin(ang) / 2;
  double L = a + b + sqrt(pow(a,2) + pow(b,2) - 2 * a * b * cos(ang));
  double h = b * sin(ang);
  printf("%lf\n%lf\n%lf\n", S, L, h);
  return 0;
}