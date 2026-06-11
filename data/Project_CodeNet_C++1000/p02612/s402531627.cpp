#include <iostream>

int main() {
  int n; std::cin >> n;
  int p = (n + 1000 - 1) / 1000;
  int ans = p * 1000 - n;
  std::cout << ans << std::endl;
  
  return 0;
}