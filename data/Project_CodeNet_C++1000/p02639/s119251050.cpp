#include <iostream>

int main() {
  int a, ans;
  for (int i = 0; i < 5; ++i) {
    std::cin >> a;
    if (a == 0)
      ans = (i + 1);
  }
  std::cout << ans << std::endl;
  
  return 0;
}