#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
const int mod = 1e9 + 7;
const int INF = 1e9;

int main() {
  int n, m;
  cin >> n >> m;
  vector<vector<int> > to(n);
  for(int i = 0; i < m; i++) {
    int a, b;
    cin >> a >> b;
    --a; --b;
    to[a].push_back(b);
  }
  int sv, tv;
  cin >> sv >> tv;
  --sv; --tv;
  vector<vector<int> > dist(n, vector<int>(3));
  for(int i = 0; i < n; i++) {
    for(int j = 0; j < 3; j++) {
      dist[i][j] = INF;
    }
  }
  queue<pair<int, int> > q;
  q.push({sv,0});
  dist[sv][0] = 0;
  while (!q.empty()) {
    int v = q.front().first;
    int l = q.front().second;
    q.pop();
    for (int u : to[v]) {
      int nl = (l+1)%3;
      if (dist[u][nl] != INF) continue;
      dist[u][nl] = dist[v][l]+1;
      q.push({u,nl});
    }
  }
  int ans = dist[tv][0];
  if (ans == INF) ans = -1;
  else ans /= 3;
  cout << ans << endl;
  return 0;
}