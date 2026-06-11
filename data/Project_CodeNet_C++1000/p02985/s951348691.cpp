#include <bits/stdc++.h>
using namespace std;

using ll = long long;

const int MAX = 510000;
static const int INF = 1e9;
static const int MOD = 1e9 + 7;

// 組合せを素数で割った値を求める
long long fac[MAX], finv[MAX], inv[MAX];

// テーブルを作る前処理
void COMinit() {
  fac[0] = fac[1] = 1;
  finv[0] = finv[1] = 1;
  inv[1] = 1;
  for (int i = 2; i < MAX; i++) {
    fac[i] = fac[i - 1] * i % MOD;
    inv[i] = MOD - inv[MOD % i] * (MOD / i) % MOD;
    finv[i] = finv[i - 1] * inv[i] % MOD;
  }
}

// 二項係数計算
long long COM(int n, int k) {
  if (n < k || n < 0 || k < 0) return 0;
  return fac[n] * (finv[k] * finv[n - k] % MOD) % MOD;
}

// 順列計算
long long PER(int n, int k) {
  if (n < k || n < 0 || k < 0) return 0;
  return fac[n] * (finv[n - k] % MOD) % MOD;
}

int k;

// 隣接リストを用いた幅優先探索 O(|V|+|E|)
vector<int> G[MAX], d(MAX, INF); // 始点sから頂点iまでの最短距離をd[i]に記録
// main関数からこれらを削除すること

ll bfs(int s) {
  ll ret = k;
  queue<int> q;
  q.push(s);
  d[s] = 0;
  while (!q.empty()) {
    int u = q.front();
    q.pop();
    int count = 0, painted = 1;
    for (int v = 0; v < G[u].size(); v++) {
      if (d[G[u][v]] == INF) {
        count++;
        d[G[u][v]] = d[u] + 1;
        q.push(G[u][v]);
      }
      else painted++;
    }
    ret *= PER(k - painted, count);
    ret %= MOD;
  }
  return ret;
}

int main() {
  cin.tie(0);
  ios::sync_with_stdio(false);
  
  // 無向(有向)グラフの隣接リスト
  int n; // n:頂点数
  cin >> n >> k;
  
  // vector<int> G[n]; // G:頂点数がnのグラフを表す隣接リスト
  
  int u, v;
  for (int i = 0; i < n - 1; i++) {
    cin >> u >> v;
    u--;
    v--;
    G[u].emplace_back(v);
    G[v].emplace_back(u); // 有向グラフではこの行をコメントアウト
  }
  
  COMinit();
  
  cout << bfs(0) << '\n';
}