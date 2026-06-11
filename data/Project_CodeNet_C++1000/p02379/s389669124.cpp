#include <stdio.h>
#include <iostream>
#include <cmath>

int main(void) {
  double x1 = 0;
  double y1 = 0;
  double x2 = 0;
  double y2 = 0;
  
  std::cin >> x1 >> y1 >> x2 >> y2;
  
  double r = std::sqrt(std::pow(x2 - x1, 2.0) + std::pow(y2 - y1, 2.0));

  printf("%.8f\n", r);

  return 0;
}