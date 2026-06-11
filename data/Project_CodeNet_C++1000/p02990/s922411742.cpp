#include <bits/stdc++.h>
using namespace std;
#define mod ((long long)(1e9 + 7))
vector<long long> fact;
vector<long long> factInv;

long long pow_mod(long long a, long long b) {
  long long ret = 1;
  while (b > 0) {
    if (b & 1) ret = ret * a % mod;
    a = a * a % mod;
    b = b >> 1;
  }
  return ret;
}

void comb_init(long long n) {
  fact.resize(n + 1);
  factInv.resize(n + 1);
  fact[0] = 1;
  for (long long i = 1; i <= n; i++) {
    fact[i] = (fact[i - 1] * i) % mod;
    fact[i] %= mod;
  }
  factInv[n] = pow_mod(fact[n], mod - 2);
  for (long long i = n - 1; i >= 0; i--) {
    factInv[i] = factInv[i + 1] * (i + 1) % mod;
  }
}

long long comb(long long n, long long r) {
  if (n == 0 && r == 0) return 1;
  if (r > n) return 0;
  long long ret = factInv[n - r] * factInv[r] % mod;
  return ret * fact[n] % mod;
}

int main(void) {
  long long N, K;
  cin >> N >> K;
  comb_init(N);
  for (long long i = 1; i <= K; i++) {
    long long ans = comb(N - K + 1, i) * comb(K - 1, i - 1) % mod;
    cout << ans << endl;
  }
  return 0;
}