#include <bits/stdc++.h>

int main() {
  int a, b, c, k; std::cin >> a >> b >> c >> k;
  int sum = 0;
  sum += std::min(a, k);
  k = std::max(k-a, 0);
  k = std::max(k-b, 0);
  sum -= std::min(c, k);
  std::cout << sum << std::endl;
  
  return 0;
}