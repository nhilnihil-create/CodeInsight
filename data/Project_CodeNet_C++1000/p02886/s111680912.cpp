#include <bits/stdc++.h>

int main() {
  int n; std::cin >> n;
  std::vector<int> d(n);
  for (int i = 0; i < n; ++i) std::cin >> d[i];
  int sum = 0;
  for (int i = 0; i < n; ++i)
    for (int j = i+1; j < n; ++j)
      sum += d[i]*d[j];
  
  std::cout << sum << std::endl;
  
  return 0;
}