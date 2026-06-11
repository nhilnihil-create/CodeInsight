// https://atcoder.jp/contests/abc132/tasks/abc132_e

#include <bits/stdc++.h>

using namespace std;

#define REP(i,n)   for(int i=0; i<(int)(n); i++)
#define FOR(i,b,e) for(int i=(b); i<=(int)(e); i++)
#define DUMP(a, n) REP(_i, n) printf("%d%c", a[_i], _i + 1 == n ? '\n' : ' ')
#define DUMP2D(a, n, m) REP(_i, n) REP(_j, m) printf("%d%c", a[_i][_j], _j + 1 == m ? '\n' : ' '); puts("")

//------------------------------------------------------------------------------
const int V_MAX = 1e5;

vector<int> G[V_MAX];

void add_edge(int u, int v) {
  G[u].push_back(v);
}

//------------------------------------------------------------------------------
const int N_MAX = 1e5;
const int INF = 1e9;

typedef pair<int, int> P;

int N, M;
int S, T;

int d[N_MAX][3];

void bfs(int s, int t) {
  queue<P> que;
  fill(d[0], d[N], INF);
  d[s][0] = 0;
  que.push(P(S, 0));
  while (!que.empty()) {
    P p = que.front(); que.pop();
    int v = p.first;
    int k = p.second;
    if (v == t && k == 0) break;
    for (int u : G[v]) {
      int k2 = (k + 1) % 3;
      int d2 = d[v][k] + 1;
      if (d[u][k2] < INF) continue;
      d[u][k2] = d[v][k] + 1;
      que.push(P(u, k2));
    }
  }
}

void solve() {
  bfs(S, T);
  // DUMP2D(d, N, 3);
  if (d[T][0] < INF) printf("%d\n", d[T][0] / 3);
  else puts("-1");
}

void input() {
  scanf("%d%d", &N, &M);
  REP(i, M) {
    int u, v;
    scanf("%d%d", &u, &v);
    add_edge(u - 1, v - 1);
  }
  scanf("%d%d", &S, &T);
  S--;
  T--;
}

int main() {
  input();
  solve();
  return 0;
}
