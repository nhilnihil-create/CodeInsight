#include <iostream>
#include <math.h>
#include <iomanip>


double distance(double x1, double y1, double x2, double y2) {
  double x, y;
  x = x1 - x2;
  y = y1 - y2;
  return sqrt(x * x + y * y);
}


int main() {
  double x1, y1, x2, y2;
  std::cin >> x1 >> y1 >> x2 >> y2;

  std::cout << std::fixed << std::setprecision(8) << distance(x1, y1, x2, y2) << std::endl;

  return 0;
}

