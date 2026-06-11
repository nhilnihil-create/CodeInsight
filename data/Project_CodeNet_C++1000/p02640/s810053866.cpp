#include <iostream>

int main() {
  int x, y; std::cin >> x >> y;
  bool ans = false;
  for (int c = 0; c < x+1; ++c) {
    int l = c*2 + (x-c)*4;
    if (l == y) ans = true;
  }
  if (ans) std::cout << "Yes" << std::endl;
  else std::cout << "No" << std::endl;
  
  return 0;
}