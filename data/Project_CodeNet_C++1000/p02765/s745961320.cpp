#include <iostream>

int main() {
  int n, r;
  std::cin >> n >> r;
  int ans = r;
  if (n < 10) ans = r + 100 * (10 - n);
  
  std::cout << ans << std::endl;
  
  return 0;
}