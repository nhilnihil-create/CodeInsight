#include <iostream>
#include <vector>

int main() {
  int n;
  std::cin >> n;
  std::vector<int> a(n), b(n), c(n);
  for (int i = 0; i < n; ++i) {
    std::cin >> a[i];
    a[i]--;
  }
  for (int i = 0; i < n; ++i)
    std::cin >> b[i];
  for (int i = 0; i < n - 1; ++i)
    std::cin >> c[i];

  int sum = 0;
  int prev = -1;
  for (int i = 0; i < n; ++i) {
    sum += b[a[i]];
    if (prev >= 0 && (prev + 1 == a[i]))
      sum += c[prev];
    prev = a[i];
  }

  std::cout << sum << std::endl;
}
