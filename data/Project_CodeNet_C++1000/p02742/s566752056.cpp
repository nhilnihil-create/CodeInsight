#include <bits/stdc++.h>

int main() {
  long long h, w;
  std::cin >> h >> w;
  if (h == 1 || w == 1) std::cout << 1 << std::endl;
  else std::cout << (h*w+2-1)/2 << std::endl;
  return 0;
}