#include <bits/stdc++.h>
using namespace std;
using ll = long long;

const ll MOD = 1000000007;
const ll MAX = 510000;
ll fac[1001000], inv[MAX], finv[MAX];

void preCOM() {
  fac[0] = fac[1] = 1;
  finv[0] = finv[1] = 1;
  inv[1] = 1;
  for (int i = 2; i < 1001000; i++) {
    fac[i] = fac[i-1] * i % MOD;
    if (i < MAX) {
      inv[i] = MOD - (inv[MOD%i] * (MOD/i)) % MOD;
      finv[i] = finv[i-1] * inv[i] % MOD;
    }
  }
}

ll COM (ll n, ll a) {
  if (n < a) return 0;
  if (n < 0 || a < 0) return 0;
  return fac[n] * (finv[a] * finv[n-a] % MOD) % MOD;
}

int main() {
  ll x, y;
  cin >> x >> y;
  if ((x+y)%3 != 0) {
    cout << 0 << endl;
    return 0;
  }
  ll p = (x+y)/3;
  ll q = min(x-p, y-p);
  preCOM();
  cout << COM(p,q) << endl;
}