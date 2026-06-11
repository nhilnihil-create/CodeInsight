// https://atcoder.jp/contests/abc132/tasks/abc132_d

#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

#define REP(i,n)   for(int i=0; i<(int)(n); i++)
#define FOR(i,b,e) for(int i=(b); i<=(int)(e); i++)
#define FORR(i,b,e) for(int i=(b); i>=(int)(e); i--)
#define DUMP(a, n) REP(_i, n) printf("%d%c", a[_i], _i + 1 == n ? '\n' : ' ')
#define DUMP2D(a, n, m) REP(_i, n) REP(_j, m) printf("%d%c", a[_i][_j], _j + 1 == m ? '\n' : ' '); puts("")


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

//------------------------------------------------------------------------------
const int F_MAX = 2000;

ll fact[F_MAX + 1];
ll fact_inv[F_MAX + 1];

void init_fact(int m) {
  fact[0] = 1;
  FOR(i, 1, F_MAX) fact[i] = fact[i - 1] * i % m;
  fact_inv[F_MAX] = mod_inverse(fact[F_MAX], m);
  FORR(i, F_MAX - 1, 0) fact_inv[i] = fact_inv[i + 1] * (i + 1) % m;
}

ll mod_comb_fast(ll n, ll k, ll mod) {
  if (n < 0 || k < 0 || n < k) return 0;
  ll a = fact[n];
  ll b = fact_inv[k] * fact_inv[n - k] % mod;
  ll ret = a * b % mod;
  // printf("%lld_C_%lld = %lld\n", n, k, ret);
  return ret;
}

//------------------------------------------------------------------------------
const int N_MAX = 2000;
const ll MOD = 1e9+7;
const int D[] = { -1, 0, 0, 1 };

int N, K;

void solve() {
  int M = N - K;
  init_fact(MOD);
  FOR(i, 1, K) {
    // i_H_(K-i) = (K-1)_C_(K-i)
    ll b = mod_comb_fast(K - 1, K - i, MOD);
    ll r = 0;
    if (M > 0) {
      for (int d : D) {
        int j = i + d;
        // j_H_(M-j) = (M-1)_C_(M-j)
        if (j <= M) r = (r + mod_comb_fast(M - 1, M - j, MOD)) % MOD;
      }
    } else {
      r = (i == 1);
    }
    ll ans = b * r % MOD;
    printf("%lld\n", ans);
  }
}

void input() {
  scanf("%d%d", &N, &K);
}

int main() {
  input();
  solve();
  return 0;
}
