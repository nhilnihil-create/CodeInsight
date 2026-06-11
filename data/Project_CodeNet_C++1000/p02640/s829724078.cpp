#include <iostream>

int main() {
  int x, y; std::cin >> x >> y;
  bool ans = true;
  // 偶数個
  if ((4*x-y)%2 != 0) ans = false;
  int crane = (4*x-y)/2;
  int turtle = x-crane;
  if (crane + turtle != x) ans = false;
  if (crane < 0) ans = false;
  if (turtle < 0) ans = false;

  if (ans) std::cout << "Yes" << std::endl;
  else std::cout << "No" << std::endl;
  
  return 0;
}
