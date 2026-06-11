#include <iostream>
#include <vector>

int main() {
  int n;
  std::cin >> n;
  std::vector<int> a(n);
  for (int i = 0; i < n; ++i) {
    std::cin >> a[i];
  }
  
  std::vector<int64_t> f(n);  // f(i):在第i天，手里最多能有多少钱.
  f[0] = 1000;
  for (int i = 1; i < n; ++i) {
    f[i] = f[i - 1];
    for (int j = 0; j < i; ++j) {
      int64_t cur = f[j] / a[j] * a[i] + f[j] % a[j];
      if (cur > f[i]) f[i] = cur;
    }
  }
  std::cout << f[n - 1] << std::endl;
  return 0;
}