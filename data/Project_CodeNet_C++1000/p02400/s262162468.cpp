#include <iostream>
#include <iomanip>
#define PI 3.141592653589

int main(int argc, char const *argv[]) {
  double r=0;
  double area=0,length=0;

  std::cin >> r;
  area = r*r*PI;
  length = 2.0 * PI * r;
  std::cout << std::fixed << std::setprecision(6) << area << " " << std::fixed << std::setprecision(6) << length << std::endl;

  return 0;
}