#include <iostream>
#include <vector>

class Combination {
private:
  const int max;
  const int mod;
  std::vector<long long> finv; // finv[k] = (k!)^-1 in Fp
public:
  Combination(int max, int mod) : max(max), mod(mod), finv(max, -1) {
    std::vector<long long> inv(max, -1); // inv[k] = k^-1 in Fp
    inv[1] = 1;
    finv[0] = finv[1] = 1;
    for (int i = 2; i < max; ++i) {
      inv[i] = mod - inv[mod % i] * (mod / i) % mod;
      finv[i] = finv[i - 1] * inv[i] % mod;
    }
  }
  long long operator()(int n, int k) const {
    if (n < k || n < 0 || k < 0)
      return 0;
    long long res = 1;
    for (int i = 0; i < k; ++i)
      res = res * (n - i) % mod;
    return res * finv[k] % mod;
  }
};

long long modpow(long long a, long long n, long long mod) {
  long long res = 1;
  while (n > 0) {
    if (n & 1)
      res = res * a % mod;
    a = a * a % mod;
    n >>= 1;
  }
  return res;
}

int main() {
  int n, a, b;
  std::cin >> n >> a >> b;
  const int MAX = 1000000;
  const int MOD = 1000000007;
  Combination comb(MAX, MOD);

  long long res = modpow(2, n, MOD) - 1;
  if (res < 0)
    res += MOD;
  res -= comb(n, a);
  if (res < 0)
    res += MOD;
  res -= comb(n, b);
  if (res < 0)
    res += MOD;
  std::cout << res << std::endl;
}
