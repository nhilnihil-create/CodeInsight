#include <iostream>
#include <iomanip>

int main(int argc, char const *argv[]) {
  int x=0,y=0;
  double d;

  std::cin >> x >> y;
  d = (double)x/y;
  std::cout << (x/y) << " " << (x%y) << " " << std::fixed << std::setprecision(5) << d << std::endl;
  return 0;
}