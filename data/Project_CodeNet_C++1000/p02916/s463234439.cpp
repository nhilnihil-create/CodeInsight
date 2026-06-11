#include <bits/stdc++.h>

int main() {
  int n; std::cin >> n;
  std::vector<int> a(n), b(n), c(n-1);
  for (int i = 0; i < n; ++i) std::cin >> a[i];
  for (int i = 0; i < n; ++i) --a[i];
  for (int i = 0; i < n; ++i) std::cin >> b[i];
  for (int i = 0; i < n-1; ++i) std::cin >> c[i];
  int sum = 0;
  for (int i = 0; i < n; ++i) {
    sum += b[a[i]];
    if (i == 0) continue;
    if (a[i] - a[i-1] == 1) sum += c[a[i-1]];
  }
  std::cout << sum << std::endl;
  return 0;
}