#include <iostream>
#include <vector>

struct Combination {
  std::vector<long long> fac, finv, inv;
  int mod;
  Combination(int max_n, int _mod) {
    fac = finv = inv = std::vector<long long>(max_n + 10, 0);
    mod = _mod;
    fac[0] = fac[1] = 1;
    finv[0] = finv[1] = 1;
    inv[1] = 1;
    for (int i = 2; i < max_n + 10; i++) {
      fac[i] = fac[i - 1] * i % mod;
      inv[i] = mod - inv[mod % i] * (mod / i) % mod;
      finv[i] = finv[i - 1] * inv[i] % mod;
    }
  }
  long long mod_comb(int n, int k) {
    if (n < k || n < 0 || k < 0) {
      return 0;
    }
    return fac[n] * (finv[k] * finv[n - k] % mod) % mod;
  }
};

int main() {
  int max_n = 2000;
  int mod = 1000000007;

  Combination comb(max_n, mod);

  int n, k;
  std::cin >> n >> k;

  for (int i = 1; i <= k; i++) {
    long long a = comb.mod_comb(n - k + 1, i);
    long long b = comb.mod_comb(k - 1, i - 1);
    std::cout << a * b % mod << "\n";
  }

  return 0;
}