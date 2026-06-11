#include <iostream>
#include <iomanip>
#include <math.h>
#include <cmath>

int main()
{
  double a, b, x;
  std::cin >> a >> b >> x;

  double rad = 0;
  if(x/a < 0.5 * a * b) {
    rad = atan((a*b*b)/(2*x));
  } else {
    rad = atan(2*(a*b - x/a)/(a*a));
  }

  if(rad < 0) {
    rad += M_PI;
  }

  double theta = rad * 180 / M_PI;

  std::cout << std::fixed << std::setprecision(15) << theta << std::endl;
  return 0;
}
