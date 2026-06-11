#include <iostream>
#include <math.h>
#include <iomanip>


#define PI 3.14159265


double area(double a, double b, double C) {
  return a * b * sin(C * PI / 180) / 2;
}


double circumference(double a, double b, double C) {
  return a + b + sqrt(a * a + b * b - 2 * a * b *cos(C * PI / 180));
}

double height(double b, double C) {
  return b * sin(C * PI / 180);
}


int main() {
  double a, b, C;
  std::cin >> a >> b >> C;

  std::cout << std::fixed << std::setprecision(8)
    << area(a, b, C) << std::endl
    << circumference(a, b, C) << std::endl
    << height(b, C) << std::endl;

  return 0;
}

