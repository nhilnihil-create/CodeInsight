#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
int dx[] = {1, 0, -1, 0}, dy[] = {0, 1, 0, -1};
using pii = pair<int, int>;
int main() {
  int v, e;
  cin >> v >> e;

  using Graph = vector<vector<int>>;

  Graph G(v);
  vector<int> d(v);

  for (int i = 0; i < e; i++) {
    int a, b;
    cin >> a >> b;
    G[a].push_back(b);
    d[b]++;
  }
  vector<int> ans;

  queue<int> que;
  for (int i = 0; i < v; i++) {
    if (d[i] == 0) {
      que.push(i);
    }
  }

  while (!que.empty()) {
    int v = que.front();
    que.pop();

    for (int i = 0; i < G[v].size(); i++) {
      int u = G[v][i];
      d[u]--;
      if (d[u] == 0) que.push(u);
    }
    ans.push_back(v);
  }

  for (int i = 0; i < ans.size(); i++) {
    cout << ans[i] << endl;
  }
}
