#include <iostream>

int main() {
  int n; std::cin >> n;
  bool inc7 = false;
  while (n) {
    if (n % 10 == 7) inc7 = true;
    n /= 10;
  }
  if (inc7) std::cout << "Yes" << std::endl;
  else std::cout << "No" << std::endl;
  
  return 0;
}