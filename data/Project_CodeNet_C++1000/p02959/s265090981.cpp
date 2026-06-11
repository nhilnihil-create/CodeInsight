#include <iostream>
#include <algorithm>

int main() {
  int n;
  std::cin >> n;
  int a[n + 1], b[n];
  for (int i = 0; i < n + 1; i++) {
    std::cin >> a[i];
  }
  for (int i = 0; i < n; i++) {
    std::cin >> b[i];
  }
  long long sum = 0;
  for (int i = 0; i < n; i++) {
    int d = std::min(a[i], b[i]);
    sum += d;
    a[i] -= d;
    b[i] -= d;
    d = std::min(a[i + 1], b[i]);
    sum += d;
    a[i + 1] -= d;
    b[i] -= d;
  }
  std::cout << sum << "\n";
  return 0;
}