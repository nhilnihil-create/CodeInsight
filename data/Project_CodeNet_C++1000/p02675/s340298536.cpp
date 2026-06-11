#include <iostream>

int main() {
  int n; std::cin >> n;
  int d1 = n%10;
  if (d1 == 3) std::cout << "bon" << std::endl;
  else if (d1 == 0 || d1 == 1 || d1 == 6 || d1 == 8) std::cout << "pon" << std::endl;
  else std::cout << "hon" << std::endl;
  
  return 0;
}