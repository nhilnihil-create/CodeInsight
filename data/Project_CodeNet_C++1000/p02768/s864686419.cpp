#include <iostream>

long long mod_pow(long long x, long long n, long long mod) {
  long long res = 1;
  while (n > 0) {
    if (n & 1) {
      res = res * x % mod;
    }
    x = x * x % mod;
    n >>= 1;
  }
  return res;
}

long long mod_inverse(long long x, long long mod) {
  return mod_pow(x, mod - 2, mod);
}

// return nCk % mod
// it takes O(k)
long long mod_comb(long long n, long long k, long long mod) {
  long long numer = 1, denom = 1;
  for (long long i = 0; i < k; i++) {
    numer = numer * ((n - i) % mod) % mod;
    denom = denom * ((i + 1) % mod) % mod;
  }
  return numer * mod_inverse(denom, mod) % mod;
}

int main() {
  const int mod = 1000000007;
  int n, a, b;
  std::cin >> n >> a >> b;

  long long ans = mod_pow(2, n, mod) - 1;
  ans = (ans - mod_comb(n, a, mod)) % mod;
  ans = (ans - mod_comb(n, b, mod)) % mod;
  ans = (ans + mod) % mod;

  std::cout << ans << "\n";

  return 0;
}