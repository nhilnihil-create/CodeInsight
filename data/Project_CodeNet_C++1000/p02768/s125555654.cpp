#include<bits/stdc++.h>
using namespace std;
using ll = long long;
using P = pair<int, int>;

constexpr int MOD = 1000000007;

template<typename T> long pow_mod(long base, T exp, const T mod = 1'000'000'007) {
  base %= mod;
  long result = 1L;
  while (exp > 0) {
    if (exp & 1) result = (result * base) % mod;
    base = (base * base) % mod;
    exp >>= 1;
  }
  return result;
}

long factrial(int n, int a) {
  if (a == 1) return n;
  return (factrial(n - 1, a - 1) * n) % MOD;
}

long comb_mod(int n, int r, const int mod = 1000000007) {
  return factrial(n, r) * pow_mod(factrial(r, r), MOD - 2) % MOD;
}

int main() {
  int n, a, b;
  cin >> n >> a >> b;
  long ans;
  ans = pow_mod(2, n) - 1;
  ans -= comb_mod(n, a) + comb_mod(n, b);
  while (ans < 0) {
    ans += MOD;
  }
  cout << ans << endl;
  return 0;
}
