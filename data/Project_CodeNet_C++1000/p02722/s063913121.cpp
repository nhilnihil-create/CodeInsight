#include <iostream>
using namespace std;

int64_t solve(int64_t n, int64_t k) {
  while (n % k == 0) {
    n /= k;
  }
  return n % k == 1;
}

int main() {
  int64_t n, result = 0;
  cin >> n;
  for (int64_t d = 1; d * d <= n; ++d) {
    if (n % d == 0) {
      if (d > 1) {
        result += solve(n, d);
      }
      if (n / d != d) {
        result += solve(n, n / d);
      }
    }
  }
  --n;
  for (int64_t d = 1; d * d <= n; ++d) {
    if (n % d == 0) {
      if (d > 1) {
        ++result;
      }
      if (d != n / d) {
        ++result;
      }
    }
  }
  cout << result;
  return 0;
}