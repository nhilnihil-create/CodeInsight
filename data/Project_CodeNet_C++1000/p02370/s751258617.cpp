#include <bits/stdc++.h>
using namespace std;

typedef long long int ll;
ll MOD = 1000000007;
ll INFL = 1ll << 60;
ll INF = 1 << 28;

vector<int> g[10010];
bool went[10010];
int topo[10010];
int c;

void dfs(int now) {
  went[now] = true;
  for (auto to : g[now])
    if (!went[to]) dfs(to);
  topo[now] = c;
  c++;
}

// ====================================================================

int main() {
  int n, m;
  cin >> n >> m;
  for (int i = 0; i < m; i++) {
    int from, to;
    cin >> from >> to;
    g[from].push_back(to);
  }

  for (int i = 0; i < n; i++) {
    if (!went[i])
      dfs(i);
  }

  vector<pair<int, int>> v;
  for (int i = 0; i < n; i++) {
    v.push_back(make_pair(topo[i], i));
  }
  sort(v.rbegin(), v.rend());
  for (int i = 0; i < n; i++) {
    cout << v[i].second << endl;
  }
}

