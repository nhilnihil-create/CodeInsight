#include <iostream>
#include <cmath>
#include <iomanip>

double distanceBetweenPoints(double x1, double y1, double x2, double y2) {
  return std::sqrt(std::pow((x2 - x1), 2) + std::pow((y2 - y1), 2));
}

int main() {

  double x1, y1, x2, y2;
  std::cin >> x1 >> y1 >> x2 >> y2;

  std::cout << std::setprecision(12) << std::fixed << distanceBetweenPoints(x1, y1, x2, y2) << std::endl;

}
