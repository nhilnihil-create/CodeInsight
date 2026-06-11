// https://atcoder.jp/contests/abc156/tasks/abc156_d

#define _GLIBCXX_DEBUG
#include <bits/stdc++.h>
using namespace std;
using ll = int64_t;

#define REP(i,n)   for(int i=0; i<(int)(n); i++)
#define FOR(i,b,e) for(int i=(b); i<=(int)(e); i++)
#if DEBUG
  #define DUMP(a) REP(_i, a.size()) cout << a[_i] << (_i + 1 == a.size() ? "\n" : " ")
  #define DUMP2D(b) REP(_j, b.size()) DUMP(b[_j]); cout << endl
#else
  #define DUMP(a)
  #define DUMP2D(b)
#endif

//------------------------------------------------------------------------------
ll mod_pow(ll x, ll n, ll mod) {
  ll res = 1;
  while (n > 0) {
    if (n & 1) {
      res = res * x % mod;
    }
    x = x * x % mod;
    n >>= 1;
  }
  return res;
}

ll mod_inverse(ll x, ll mod) {
  return mod_pow(x, mod - 2, mod);
}

ll mod_comb2(ll n, ll k, ll mod) {
  if (n < 0 || k < 0 || n < k) return 0;
  if (k > n - k) k = n - k;
  if (k == 0) return 1;
  ll a = 1, b = 1;
  while(k > 0) {
    a = a * n-- % mod;
    b = b * k-- % mod;
  }
  return a * mod_inverse(b, mod) % mod;
}

//------------------------------------------------------------------------------
const int N_MAX = 1e9;
const int MOD = 1e9+7;

int n, a, b;

int main() {
  cin >> n >> a >> b;

  ll ans = mod_pow(2, n, MOD);
  ans = (ans + MOD - 1) % MOD;
  ans = (ans + MOD - mod_comb2(n, a, MOD)) % MOD;
  ans = (ans + MOD - mod_comb2(n, b, MOD)) % MOD;

  cout << ans << endl;
}
