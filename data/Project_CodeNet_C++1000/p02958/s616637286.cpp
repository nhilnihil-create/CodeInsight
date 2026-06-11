#include <iostream>
#include <vector>

int main() {
  int n; std::cin >> n;
  int cnt = 0;
  for (int i = 1; i <= n; ++i) {
    int e; std::cin >> e;
    if (e != i) ++cnt;
  }
  if (cnt <= 2) std::cout << "YES" << std::endl;
  else std::cout << "NO" << std::endl;
  
  return 0;
} 