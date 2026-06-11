#include "bits/stdc++.h"
using namespace std;
using ll = long long;
using Pii = pair<int, int>;
using Pll = pair<ll, ll>;
#define rep(i, begin, n) for (int i = begin; i < n; i++)
#define repe(i, begin, n) for (int i = begin; i <= n; i++)
#define repr(i, begin, n) for (int i = begin; i > begin - n; i--)
#define repre(i, begin, end) for (int i = begin; i >= end; i--)

template <class T>
inline bool chmax(T &a, T b) {
  if (a < b) {
    a = b;
    return 1;
  }
  return 0;
}

template <class T>
inline bool chmin(T &a, T b) {
  if (a > b) {
    a = b;
    return 1;
  }
  return 0;
}

const int inf = 1000000007;
const int MOD = 1000000007;
const long long INF = 1000000000000000007;

// -------------------------------------------------------

const int MAX = 1010101;

long long fac[MAX], finv[MAX], inv[MAX];

void binom_init() {
  fac[0] = fac[1] = 1;
  finv[0] = finv[1] = 1;
  inv[1] = 1;
  for (int i = 2; i < MAX; i++) {
    fac[i] = fac[i - 1] * i % MOD;
    inv[i] = MOD - inv[MOD % i] * (MOD / i) % MOD;
    finv[i] = finv[i - 1] * inv[i] % MOD;
  }
}

long long binom(int n, int k) {
  if (n < k) return 0;
  if (n < 0 || k < 0) return 0;
  return fac[n] * (finv[k] * finv[n - k] % MOD) % MOD;
}

long long perm(int n, int k) {
  if (n < k) return 0;
  if (n < 0 || k < 0) return 0;
  return fac[n] * finv[n - k] % MOD;
}

ll N, K;
vector<ll> Graph[101010];

ll dfs(ll cur, ll from) {
  ll res = 1;
  ll cnt = 0;
  for (auto nv : Graph[cur]) {
    if (nv == from) continue;

    res *= dfs(nv, cur);
    res %= MOD;
    ++cnt;
  }

  if (from == 0) {
    return res * perm(K - 1, cnt) % MOD;
  } else {
    return res * perm(K - 2, cnt) % MOD;
  }
}

int main() {
  cin >> N >> K;
  rep(i, 0, N - 1) {
    ll a, b;
    cin >> a >> b;
    Graph[a].push_back(b);
    Graph[b].push_back(a);
  }

  binom_init();

  cout << K * dfs(1, 0) % MOD;
}
