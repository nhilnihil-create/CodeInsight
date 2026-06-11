#include <bits/stdc++.h>

int main() {
  int n, m; std::cin >> n >> m;
  std::vector<int> a(n);
  for (int i = 0; i < n; ++i) std::cin >> a[i];
  int sum = std::accumulate(a.begin(), a.end(), 0);
  int cnt = 0;
  for (int i = 0; i < n; ++i)
    if (a[i] >= ((double)sum / (4*m))) ++cnt;
  
  if (cnt >= m) std::cout << "Yes" << std::endl;
  else std::cout << "No" << std::endl;
  
  return 0;
  
}