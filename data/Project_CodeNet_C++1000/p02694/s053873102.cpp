#include <iostream>

int main() {
  long long x; std::cin >> x;
  long long d = 100;
  long long y = 0;
  
  while (d < x) {
    d += (d / 100);
    ++y;
  }
  
  std::cout << y << std::endl;
  
  return 0;
}