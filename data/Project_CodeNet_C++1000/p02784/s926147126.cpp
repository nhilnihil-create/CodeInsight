#include <iostream>

int main() {
  int h, n; std::cin >> h >> n;
  int attack_sum = 0;
  while (n--) {
    int a; std::cin >> a;
    attack_sum += a;
  }
  if (h <= attack_sum) std::cout << "Yes" << std::endl;
  else std::cout << "No" << std::endl;
  
  return 0;
}