#include <bits/stdc++.h>

int main() {
  int a, b; std::cin >> a >> b;

  for (int m = 13; m <= 1000; ++m) {
    if((int)(m*0.08) == a && (int)(m*0.10) == b) {
      std::cout << m << std::endl;
      return 0;
    }
  }
  std::cout << -1 << std::endl;
}
