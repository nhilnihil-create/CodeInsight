#include <bits/stdc++.h>

#include <iostream>
//#include <algorithm>
// #include <iomanip>
#define ll long long
#define map unordered_map
#define set unordered_set
#define pll pair<ll, ll>
#define vll vector<ll>

using namespace std;

const ll MOD = 1000000007LL;
const ll INF = (1LL << 60LL);

const int MAX = 510000;

long long fac[MAX], finv[MAX], inv[MAX];

void initComb() {
  fac[0] = fac[1] = 1;
  finv[0] = finv[1] = 1;
  inv[1] = 1;
  for (int i = 2; i < MAX; i++) {
    fac[i] = fac[i - 1] * i % MOD;
    inv[i] = MOD - inv[MOD % i] * (MOD / i) % MOD;
    finv[i] = finv[i - 1] * inv[i] % MOD;
  }
}

long long comb(int n, int k) {
  if (n < k) {
    return 0;
  }
  if (n < 0 || k < 0) {
    return 0;
  }
  return fac[n] * (finv[k] * finv[n - k] % MOD) % MOD;
}

ll pow(ll v, ll n) {
  ll r = 1;
  for (ll i = 0; i < n; i++) {
    r *= v;
    r %= MOD;
  }
  return r;
}

int main() {
  initComb();

  ll N, K;
  scanf("%lld %lld", &N, &K);

  ll red = N - K;

  for (ll i = 1; i <= K; i++) {
    ll places = red + 1;
    ll rest = K - i;

    ll p = comb(places, i);
    ll m = comb(K - 1, i - 1);

    cout << ((p * m) % MOD) << endl;
  }
}
