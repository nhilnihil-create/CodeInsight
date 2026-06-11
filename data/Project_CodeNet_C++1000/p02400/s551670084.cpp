//Circle

#include <iostream>
#include <cmath>

namespace {

constexpr double pi()
{
  return std::atan(1.0) * 4.0;
}

}

int main()
{
  double radius;
  std::cin >> radius;
  
  const double area = radius * radius * pi();
  const double circumference = 2 * radius * pi();

  printf("%f %f\n", area, circumference);

  return 0;
}