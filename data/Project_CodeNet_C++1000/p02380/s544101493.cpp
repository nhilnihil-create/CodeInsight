#define _USE_MATH_DEFINES
#include <cmath>
#include <cstdio>
#include <iostream>

int main() {
  int a;
  int b;
  int C;
  std::cin >> a >> b >> C;

  double d2a = M_PI / 180;
  double area;
  area = 0.5 * a * b * sin(C * d2a);

  double c;
  c = sqrt((a * a) + (b * b) - 2 * a * b * cos(C * d2a));
  double circumference;
  circumference = a + b + c;

  double height;
  height = b * sin(C * d2a);

  printf("%.4f\n", area);
  printf("%.4f\n", circumference);
  printf("%.4f\n", height);

  return 0;
}