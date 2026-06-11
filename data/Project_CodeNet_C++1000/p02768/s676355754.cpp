#include <bits/stdc++.h>
using namespace std;
using Graph = vector<vector<int>>;
#define ll long long
#define _GLIBCXX_DEBUG
const ll MOD = 1000000007;
const ll Mod = 998244353;
const int MAX = 510000;
const double PI = 3.14159265358979;
const vector<int> dx = {1, 0};
const vector<int> dy = {0, 1};

// a^n modを計算する(二分累乗法)
ll modpow(ll a, ll n, ll mod) {
  ll res = 1;
  while (n>0) {
    if (n&1) res = res*a%mod;
    a = a*a%mod;
    n >>= 1;
  }
  return res;
}

// mod. m でのaの逆元a^{-1}を計算する
ll modinv(ll a, ll m) {
  ll b = m, u = 1LL, v = 0LL;
  while (b) {
    ll t = a/b;
    a -= t*b;
    swap(a, b);
    u -= t*v;
    swap(u, v);
  }
  u %= m;
  if (u<0) u += m;
  return u;
}

// 二項係数(O(k))
ll comb(ll n, ll k) {
  ll num = 1, den = 1; // 分子と分母
  for (ll i=n; i>=n-k+1; i--) num = num*i%MOD;
  for (ll i=1; i<=k; i++) den = den*i%MOD;
  num %= MOD;
  return num*modinv(den, MOD)%MOD;
}

int main() {
  ll n, a, b;
  cin >> n >> a >> b;
  ll res = modpow(2, n, MOD)-comb(n, a)-comb(n, b)-1;
  res %= MOD;
  if (res<0) res += MOD;
  cout << res << endl;
}