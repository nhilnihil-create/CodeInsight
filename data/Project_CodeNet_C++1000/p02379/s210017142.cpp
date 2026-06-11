#include <math.h>
#include <iomanip>
#include <iostream>

int main() {
  double x1, y1, x2, y2;
  std::cin >> x1 >> y1 >> x2 >> y2;
  std::cout << std::fixed << std::setprecision(12)
            << sqrt(pow(x1 - x2, 2.0) + pow(y1 - y2, 2.0)) << std::endl;
  return 0;
}

