#include <bits/stdc++.h>

#include <iostream>
//#include <algorithm>
// #include <iomanip>
#define ll long long
#define map unordered_map
#define set unordered_set
#define pll pair<ll, ll>
#define vll vector<ll>
#define mll map<ll, ll>

using namespace std;

const ll MOD = 1000000007LL;
const ll INF = (1LL << 60LL);

// const int MAX = 510000;
const int MAX = 2000010;

ll fac[MAX], finv[MAX], inv[MAX];

void init_ncr() {
  fac[0] = fac[1] = 1;
  finv[0] = finv[1] = 1;
  inv[1] = 1;
  for (int i = 2; i < MAX; i++) {
    fac[i] = fac[i - 1] * i % MOD;
    inv[i] = MOD - inv[MOD % i] * (MOD / i) % MOD;
    finv[i] = finv[i - 1] * inv[i] % MOD;
  }
}

ll ncr(int n, int k) {
  if (n < k) return 0;
  if (n < 0 || k < 0) return 0;
  return fac[n] * (finv[k] * finv[n - k] % MOD) % MOD;
}
ll npr(ll val1, ll val2) {
  ll c = ncr(val1, val2);
  return c * fac[val2] % MOD;
}

int main() {
  init_ncr();

  ll X, Y;
  scanf("%lld %lld", &X, &Y);

  ll h = -1;
  ll v = -1;

  for (ll c1 = 0; c1 <= X; c1++) {
    ll c2 = (X - c1) / 2;
    if ((X - c1) % 2 == 1) {
      continue;
    }

    if (Y == c1 * 2 + c2) {
      h = c1;
      v = c2;
      break;
    }
  }

  if (h == -1) {
    cout << (0) << endl;
    return 0;
  }

  cout << (ncr(h + v, v)) << endl;
}
