#include <cmath>
#include <iomanip>
#include <iostream>

double rad(double& angle) { return angle / 180 * M_PI; }
double cosine(double& a, double& b, double& rad) {
  return sqrt(pow(a, 2.0) + pow(b, 2.0) - 2 * a * b * cos(rad));
}
double area(double& a, double& b, double& rad) { return a * b * sin(rad) / 2; }
double circumference(double& a, double& b, double& rad) {
  return a + b + cosine(a, b, rad);
}
double height(double& a, double& b, double& rad) { return b * sin(rad); }

int main() {
  double a, b, angle;
  std::cin >> a >> b >> angle;
  double theta = rad(angle);
  std::cout << std::fixed << std::setprecision(5);
  std::cout << area(a, b, theta) << std::endl;
  std::cout << circumference(a, b, theta) << std::endl;
  std::cout << height(a, b, theta) << std::endl;
  return 0;
}

