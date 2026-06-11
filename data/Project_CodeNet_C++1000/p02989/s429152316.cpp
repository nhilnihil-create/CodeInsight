#include <iostream>
#include <algorithm>

int main() {
  int n;
  std::cin >> n;
  if (n % 2 == 1) {
    std::cout << 0 << "\n";
    return 0;
  }
  int d[n];
  for (int i = 0; i < n; i++) {
    std::cin >> d[i];
  }
  std::sort(d, d + n);
  std::cout << d[n / 2] - d[n / 2 - 1] << "\n";
  return 0;
}