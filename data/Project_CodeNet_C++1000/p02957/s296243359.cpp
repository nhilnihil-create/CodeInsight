#include <bits/stdc++.h>

int main() {
  int a, b; std::cin >> a >> b;
  int d = std::abs(a-b);
  if (d%2 == 0) std::cout << d/2 + (a > b ? b : a) << std::endl;
  else std::cout << "IMPOSSIBLE" << std::endl;
  
  return 0;
}