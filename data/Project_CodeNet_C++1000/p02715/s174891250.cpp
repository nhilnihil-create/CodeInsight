#include <iostream>
#include <vector>

long long modpow(int a, long long n, int mod) {
  long long res = 1;
  long long apow = a; // a^1, a^2, a^4, ...
  while (n) {
    if (n & 1LL)
      res = (res * apow) % mod;
    apow = apow * apow % mod;
    n = n >> 1;
  }
  return res;
}

int main() {
  int N, K;
  std::cin >> N >> K;

  int mod = 1000000007;
  long long res = 0;
  std::vector<long long> dp(K + 1, 0);
  for (int v = K; v >= 1; --v) {
    long long tmp = modpow(K / v, N, mod);
    int p = 2;
    while (p * v <= K) {
      tmp -= dp[p * v];
      if (tmp < 0)
        tmp += mod;
      p += 1;
    }
    dp[v] = tmp;
    res = (res + v * tmp) % mod;
  }
  std::cout << res << std::endl;
}
