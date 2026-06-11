#include <iostream>
#include <iomanip>
int main(void)
{
  int a, b, d, r;
  double f;
  std::cin >> a >> b;
  d = a / b;
  r = a % b;
  f = a / static_cast<double>(b);
  std::cout << d << " " << r << " " << std::fixed << std::setprecision(5) << f << std::endl;
}