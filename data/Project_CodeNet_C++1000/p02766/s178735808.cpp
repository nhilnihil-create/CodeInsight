#include <iostream>

int main() {
  int n, k; std::cin >> n >> k;
  int d = 0;
  while (n) {
    ++d;
    n /= k;
  }
  std::cout << d << std::endl;
  
  
  return 0;
}