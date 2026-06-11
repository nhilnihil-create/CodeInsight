#include <iostream>

int main() {
  int x, y; std::cin >> x >> y;
  std::cout << (y%2==0 && 2*x<=y && y<=4*x ? "Yes" : "No") << std::endl;
  return 0;
}