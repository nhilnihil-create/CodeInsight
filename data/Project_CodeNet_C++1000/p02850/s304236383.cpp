#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define FOR(i, a, b) for (int i = (a); i < (b); ++i)
#define REP(i, n) for (int i = (0); i < (n); ++i)
#define ALL(obj) (obj).begin(), (obj).end()
#define DEBUG(val) cout << #val << " : " << val << endl
#define MOD 1000000007
#define chmin(a, b) a = min(a, b)
#define chmax(a, b) a = max(a, b)

int k = 0;
using Graph = vector<vector<int>>;
vector<bool> seen;
map<pair<int, int>, int> ans;

void dfs(const Graph &G, int v, int parent_color = 0) {
  seen[v] = true;
  int now_color = 1;
  for (auto next_v : G[v]) {
    if (seen[next_v]) continue;
    if (now_color == parent_color) now_color++;
    ans[make_pair(v, next_v)] = now_color;
    ans[make_pair(next_v, v)] = now_color;
    dfs(G, next_v, now_color);
    now_color++;
  }
}

int main() {
  int n;
  cin >> n;
  int cnt[100005] = {};
  vector<pair<int, int>> nodes;
  Graph G(n + 1);
  REP(i, n - 1) {
    int x, y;
    cin >> x >> y;
    nodes.push_back(make_pair(x - 1, y - 1));
    G[x - 1].push_back(y - 1);
    G[y - 1].push_back(x - 1);
    chmax(k, max(++cnt[x - 1], ++cnt[y - 1]));
  }
  cout << k << endl;
  seen.assign(n + 1, false);
  dfs(G, 0);
  for (auto p : nodes) {
    cout << ans[p] << endl;
  }
}
