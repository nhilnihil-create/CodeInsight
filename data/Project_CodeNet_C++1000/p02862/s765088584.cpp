#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using ull = unsigned long long;
using pii = pair<int, int>;
using pll = pair<ll, ll>;
using pull = pair<ull, ll>;
#define INF 1000000000
#define LLINF 10000000000000000ll
#define MOD 1000000007LL

bool dbgflag = false;

ll modPow(ll a, ll n, ll p) {
  if (n == 1) return a % p;
  if (n % 2 == 1) return (a * modPow(a, n-1, p)) % p;
  ll t = modPow(a, n/2, p);
  return (t * t) % p;
}

int main() {
  cin.tie(0);
  ios::sync_with_stdio(false);

  ll x, y;
  cin >> x >> y;
  if (((2 * y - x) % 3 != 0) || ((2 * x - y) % 3 != 0)) {
    cout << 0 << endl;
    return 0;
  }

  ll a = (2 * y - x) / 3, b = (2 * x - y) / 3;
  if (!((a >= 0) && (b >= 0))) {
    cout << 0 << endl;
    return 0;
  }
  ll n = a + b;
  vector<ll> fact(n+1); //階乗
  vector<ll> fact_inv(n+1); //階乗の逆元
  fact[0] = 1;
  for (int i = 0; i < n; i++) fact[i+1] = (fact[i] * (i+1)) % MOD;
  fact_inv[n] = modPow(fact[n], MOD-2, MOD);
  for (int i = n-1; i >= 0; i--) fact_inv[i] = (fact_inv[i+1] * (i+1)) % MOD;

  auto comb = [&](ll n0, ll r) { //MODで
    return (((fact[n0] * fact_inv[n0-r]) % MOD) * fact_inv[r]) % MOD;
  };

  cout << comb(a+b, a) << endl;
}
