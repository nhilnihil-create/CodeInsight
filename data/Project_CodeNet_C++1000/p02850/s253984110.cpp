#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using ull = unsigned long long;
using pii = pair<int, int>;
using pll = pair<ll, ll>;
#define INF 1000000000
#define LLINF 10000000000000000ll
#define MOD 1000000007

bool dbgflag = true;

struct edge {
  int color = -1;
  vector<int> to;
};

void dfs(int i, int col, vector<edge>&edges) {
  edges[i].color = col;
  int c = 1;
  for (int nx: edges[i].to) {
    if (c == col) c++;
    if (edges[nx].color == -1) {
      dfs(nx, c, edges);
      c++;
    }
  }
  return;
}

int main() {
  cin.tie(0);
  ios::sync_with_stdio(false);

  int n;
  cin >> n;
  vector<edge> edges(n);
  vector<pii> rec;
  for (int i = 0; i < n-1; i++) {
    int a, b;
    cin >> a >> b;
    a--, b--;
    edges[a].to.emplace_back(b);
    edges[b].to.emplace_back(a);
    rec.emplace_back(pii(a, b));
  }
  
  dfs(0, 0, edges);

  int mx = 0;
  for (int i = 0; i < n; i++) {
    mx = max(mx, (int)edges[i].to.size());
  }
  cout << mx << endl;

  for (int i = 0; i < n-1; i++) {
    cout << edges[rec[i].second].color << endl;
  }
}
