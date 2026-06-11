#include <bits/stdc++.h>
using namespace std;
#define REP(i, n) for (int i = 0; i < (int)(n); i++)
#define FOR(i, a, b) for (int i = (a); i < (b); ++i)
typedef long long ll;
typedef pair<int, int> P;
const int INF = 100100100;
const int MOD = (int)1e9 + 7;
const double EPS = 1e-9;
struct Edge {
  /* data */
  int to, id;
};

vector<vector<Edge>> g;
vector<int> ans;
void dfs(int v, int c = -1, int p = -1) {
  int k = 1;
  REP(i, g[v].size()) {
    int u = g[v][i].to, ei = g[v][i].id;
    if (u == p) continue;
    if (k == c) k++;
    ans[ei] = k;
    k++;
    dfs(u, ans[ei], v);
  }
}
int main() {
  int N;
  cin >> N;
  g.resize(N);
  ans.resize(N);
  REP(i, N - 1) {
    int a, b;
    cin >> a >> b, a--, b--;
    g[a].push_back(Edge{b, i});
    g[b].push_back(Edge{a, i});
  }
  dfs(0);
  int mx = 0;
  REP(i, N) mx = max(mx, int(g[i].size()));
  cout << mx << endl;
  REP(i, N - 1) { cout << ans[i] << endl; }
}