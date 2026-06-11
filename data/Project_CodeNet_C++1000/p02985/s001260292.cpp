// https://atcoder.jp/contests/abc133/tasks/abc133_e

#define _GLIBCXX_DEBUG
#include <bits/stdc++.h>
using namespace std;

typedef int64_t ll;

#define REP(i,n)   for(int i=0; i<(int)(n); i++)
#define FOR(i,b,e) for(int i=(b); i<=(int)(e); i++)
#define FORR(i,b,e) for(int i=(b); i>=(int)(e); i--)
#define DUMP(a, n) REP(_i, n) cout << a[_i] << (_i + 1 == n ? endl : ' ')
#define DUMP2D(a, n, m) REP(_i, n) REP(_j, m) cout << a[_i][_j] << (_j + 1 == m ? endl : ' '); cout << endl

//------------------------------------------------------------------------------
int extgcd(int a, int b, int &x, int &y) {
  int ret = a;
  if (b == 0) {
    x = 1;
    y = 0;
  } else {
    ret = extgcd(b, a % b, y, x);
    y -= (a / b) * x;
  }
  return ret;
}

int mod_inverse(int a, int m) {
  int x, y;
  extgcd(a, m, x, y);
  return (m + x % m) % m;
}

//------------------------------------------------------------------------------
const int F_MAX = 1e5;

ll fact[F_MAX + 1];
ll fact_inv[F_MAX + 1];

void init_fact(int m) {
  fact[0] = 1;
  FOR(i, 1, F_MAX) fact[i] = fact[i - 1] * i % m;
  fact_inv[F_MAX] = mod_inverse(fact[F_MAX], m);
  FORR(i, F_MAX - 1, 0) fact_inv[i] = fact_inv[i + 1] * (i + 1) % m;
}

ll mod_permutation(ll n, ll m, ll mod) {
  if (m > n) return 0LL;
  return fact[n] * fact_inv[n - m] % mod;
}

//------------------------------------------------------------------------------
const int N_MAX = 1e5;
const int K_MAX = 1e5;
const int MOD = 1'000'000'007;

int N, K;
vector<vector<int>> G;

void add_edge(int u, int v) {
  G[u].push_back(v);
  G[v].push_back(u);
}

void dfs(int p, int v, ll &x) {
  int n = p < 0 ? K - 1 : K - 2;
  int m = p < 0 ? G[v].size() : G[v].size() - 1;
  // cout << n << ' ' << m << ' ' << mod_permutation(n, m, MOD) << endl;
  x = x * mod_permutation(n, m, MOD) % MOD;
  for (int u : G[v]) {
    if (u == p) continue;
    dfs(v, u, x);
  }
}

int main() {
  cin >> N >> K;
  G = vector<vector<int>>(N);
  REP(i, N - 1) {
    int a, b;
    cin >> a >> b;
    add_edge(a - 1, b - 1);
  }

  init_fact(MOD);

  ll ans = K;
  dfs(-1, 0, ans);
  cout << ans << endl;
}
