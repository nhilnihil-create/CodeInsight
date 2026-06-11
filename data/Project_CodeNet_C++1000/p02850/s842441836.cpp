#include <bits/stdc++.h>
using namespace std;

struct Edge {
  int to;
  int index;
};

int main() {
  int n;
  cin >> n;

  vector<vector<Edge>> g(n);
  for (int i = 0; i < n - 1; ++i) {
    int a, b;
    cin >> a >> b;
    --a, --b;
    g[a].push_back(Edge{b, i});
  }

  int k = 0;
  vector<bool> visited(n);
  queue<pair<int, int>> q;
  q.emplace(0, 0);

  vector<int> color(n - 1);
  while (!q.empty()) {
    int p = q.front().first;
    int c0 = q.front().second;
    q.pop();
    visited[p] = true;
    int cc = 1;
    for (Edge e : g[p]) {
      if (visited[e.to]) {
        continue;
      }
      while (cc == c0) {
        ++cc;
      }
      color[e.index] = cc;
      q.emplace(e.to, cc);
      k = max(k, cc);
      ++cc;
    }
  }

  cout << k << endl;
  for (int i = 0; i < n - 1; ++i) {
    cout << color[i] << endl;
  }
}