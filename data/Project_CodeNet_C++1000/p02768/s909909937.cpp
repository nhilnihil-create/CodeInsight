#include <iostream>
#include <vector>

class Combination {
private:
  const int max;
  const int mod;
  std::vector<long long> inv; // inv[k] = k^-1 in Fp
  std::vector<long long> com; // com[k] = nCk
public:
  Combination(int max, int mod)
      : max(max), mod(mod), inv(max, -1), com(max, -1) {
    inv[1] = 1;
    for (int i = 2; i < max; ++i) {
      inv[i] = mod - inv[mod % i] * (mod / i) % mod;
    }
  }
  void setn(int n) {
    com[0] = 1;
    for (int k = 1; k < max; ++k)
      com[k] = (com[k - 1] * (n - k + 1) % mod) * inv[k] % mod;
  }
  long long operator()(int k) const {
    if (k < 0)
      return 0;
    return com[k];
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
  comb.setn(n);
  long long res = modpow(2, n, MOD) - 1;
  if (res < 0)
    res += MOD;
  res -= comb(a);
  if (res < 0)
    res += MOD;
  res -= comb(b);
  if (res < 0)
    res += MOD;
  std::cout << res << std::endl;

  // for (int n = 0; n < 10; ++n) {
  //   comb.setn(n);
  //   for (int k = 0; k <= 10; ++k) {
  //     std::cout << " " << comb(k);
  //   }
  //   std::cout << std::endl;
  // }
}
