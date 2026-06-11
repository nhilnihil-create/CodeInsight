#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for (int i = 0; i < (int)n; ++i)
#define repi(i, a, b) for (int i = int(a); i < int(b); ++i)
#define repr(i, n) for (int i = (int)n - 1; i >= 0; --i)
#define ALL(a) (a).begin(), (a).end()
using ll = long long;
using Graph = vector<vector<int>>;
using P = pair<ll, ll>;
const int dx[] = {0, -1, 0, 1};
const int dy[] = {1, 0, -1, 0};
const ll mod = 1e9 + 7;
const ll INF = 1e9;
const ll LINF = 1LL << 60;

struct edge {
  int to, id;  //先の頂点番号と辺番号
};

vector<vector<edge>> g;
vector<int> ans;

void dfs(int s, int c = -1, int p = -1) {
  int col = 1;
  rep(i, g[s].size()) {
    int u = g[s][i].to, v = g[s][i].id;
    if (u == p) continue;
    if (col == c) col++;
    ans[v] = col;
    col++;
    dfs(u, ans[v], s);
  }
}

int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  //////////////////////////////////////
  int n;
  cin >> n;
  g.resize(n);
  ans.resize(n - 1);
  rep(i, n - 1) {
    int a, b;
    cin >> a >> b;
    --a;
    --b;
    g[a].push_back(edge{b, i});
    g[b].push_back(edge{a, i});
  }
  dfs(0);
  int mx = 0;
  rep(i, n) mx = max(mx, (int)g[i].size());
  cout << mx << endl;
  rep(i, n - 1) cout << ans[i] << endl;
  return 0;
}
