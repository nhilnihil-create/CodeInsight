#include <iostream>

int main() {
  int n, d; std::cin >> n >> d;
  int range = 2*d + 1;
  int ans = (n + range - 1) / range;
  std::cout << ans << std::endl;
  
  return 0;
}