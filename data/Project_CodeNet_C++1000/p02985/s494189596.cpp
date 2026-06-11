#include <iostream>
#include <queue>

using namespace std;
using ll = long long;
using vi = vector<int>;
using vvi = vector<vi>;

#define rep(i,n) for(int i=0;i<(n);++i)
const int MOD = 1e9+7,
      MAX_N = 1e5+1,
      MAX = 1e5+1;
ll fac[MAX], finv[MAX], inv[MAX];

void comb_init() {
  fac[0] = fac[1] = 1;
  finv[0] = finv[1] = 1;
  inv[1] = 1;
  for (int i = 2; i < MAX; i++){
    fac[i] = fac[i - 1] * i % MOD;
    inv[i] = MOD - inv[MOD%i] * (MOD / i) % MOD;
    finv[i] = finv[i - 1] * inv[i] % MOD;
  }
}

ll comb(int n, int k){
  if (n < k) return 0;
  if (n < 0 || k < 0) return 0;
  return fac[n] * (finv[k] * finv[n - k] % MOD) % MOD;
}


int main() {
  int N, K; cin >> N >> K;

  comb_init();
  vvi edge(N, vi());
  bool visited[N];
  rep(i, N-1) {
    int a, b; cin >> a >> b;
    --a, --b;
    edge[a].push_back(b);
    edge[b].push_back(a);
    visited[i] = false;
  }
  visited[N-1] = false;

  queue<int> q;
  q.push(0);
  ll ans = K;
  while (!q.empty()) {
    int from = q.front(); q.pop();
    visited[from] = true;

    int child = edge[from].size()-1;
    if (from == 0) ++child;

    for (const auto& to : edge[from]) {
      if (!visited[to])
        q.push(to);
    }
    if (from == 0) ans *= comb(K-1, child) * fac[child] % MOD;
    else ans *= comb(K-2, child) * fac[child] % MOD;

    ans %= MOD;
  }
  cout << ans << endl;

  return 0;
}
