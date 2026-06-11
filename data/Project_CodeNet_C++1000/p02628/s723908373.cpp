#include <bits/stdc++.h>

int main() {
  int n, k; std::cin >> n >> k;
  std::vector<int> p(n);
  for (int i = 0; i < n; ++i) std::cin >> p[i];
  
  std::sort(p.begin(), p.end());
  
  int sum = 0;
  for (int i = 0; i < k; ++i) sum += p[i];
  
  std::cout << sum << std::endl;
  return 0;
}