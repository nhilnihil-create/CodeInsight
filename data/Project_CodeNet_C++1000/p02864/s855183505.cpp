#include <cmath>
#include <iostream>
#include <limits>
#include <utility>
#include <vector>

template <class T> void chmin(T &a, const T &b) {
  if (b < a)
    a = b;
}

int main() {
  using i64 = long long;
  int n, k;
  std::cin >> n >> k;
  std::vector<i64> h(n);
  for (auto &e : h) {
    std::cin >> e;
  }
  h.insert(h.begin(), 0);
  h.insert(h.end(), 0);
  n += 2;
  k = n - k - 1;
  static constexpr i64 Inf = std::numeric_limits<i64>::max() / 2;
  std::vector<i64> dp(n, Inf);
  dp[0] = 0;
  for (int l = 0; l != k; l += 1) {
    std::vector<i64> nx(n, Inf);
    for (int i = 0; i != n; i += 1) {
      for (int j = 0; j != i; j += 1) {
        chmin(nx[i], dp[j] + std::abs(h[i] - h[j]));
      }
    }
    dp = std::move(nx);
  }
  std::cout << dp.back() / 2 << std::endl;
}