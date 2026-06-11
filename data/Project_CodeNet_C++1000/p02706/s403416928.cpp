#include <iostream>
#include <bits/stdc++.h>

int main() {
  int n, m; std::cin >> n >> m;
  int sum = 0;
  for (int i = 0; i < m; ++i) {
    int a; std::cin >> a;
    sum += a;
  }
  std::cout << std::max(n-sum, -1) << std::endl;
  
  return 0;
}
