#include <iostream>

int main() {
  int n, k; std::cin >> n >> k;
  int cnt = 0;
  while (n--) {
    int h; std::cin >> h;
    if (h >= k) ++cnt;
  }
  std::cout << cnt << std::endl;
  
  return 0;
}