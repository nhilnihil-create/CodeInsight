#include <iostream>
#include <cstdio>
#include <cmath>

int main(void) {
  int a = 0;
  int b = 0;
  int C = 0;

  std::cin >> a >> b >> C;

  double h = b * std::sin(C * (M_PI / 180.0));
  double S = (a * h) / 2.0;
  
  double x = std::sqrt(std::pow(a, 2.0) + std::pow(b, 2.0) - 2.0 * a * b * std::cos(C * (M_PI / 180.0)));

  double L = a + b + x;

  std::printf("%f %f %f\n", S, L, h);
  
  return 0;
}