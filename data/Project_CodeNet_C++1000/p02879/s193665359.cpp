#include <iostream>

int main() {
  int a, b; std::cin >> a >> b;
  if (1 <= a && a <= 9 && 1 <= b && b <= 9) std::cout << a*b << std::endl;
  else std::cout << -1 << std::endl;
  
  return 0;
}