#include <iostream>

int main() {
  int n; std::cin >> n;
  long long sum = 0;
  for (int i = 1; i <= n; ++i) {
    if (i%3 == 0 || i%5 == 0) continue;
    sum += i;
  }
  std::cout << sum << std::endl;
  
  return 0;
}