#include <bits/stdc++.h>

using namespace std;
using ll = long long;
using P = pair<int, int>;

#define rep(i, n) for (int i = 0; i < (int)(n); ++i)

int main() {
  int n;
  cin >> n;
  vector<int> to[n], deg(n);
  vector<P> edge;
  rep(i, n - 1) {
    int a, b;
    cin >> a >> b;
    --a, --b;
    to[a].push_back(b);
    to[b].push_back(a);
    ++deg[a], ++deg[b];
    edge.push_back({a, b});
  }

  int mx = 0;
  rep(i, n) mx = max(mx, deg[i]);

  vector<int> ng[n];
  map<P, int> color;
  queue<int> q;
  q.push(0);
  while (!q.empty()) {
    int u = q.front();
    q.pop();

    vector<bool> ok(mx, true);
    for (auto v : ng[u]) ok[v] = false;

    int c = 0;
    for (auto v : to[u]) {
      P p1 = P(u, v), p2 = P(v, u);
      if (color.count(p1) == 1 || color.count(p2) == 1) continue;
      while (ok[c] == false) ++c;
      color[p1] = color[p2] = c;
      ok[c] = false;
      ng[v].push_back(c);
      q.push(v);
    }
  }

  cout << mx << endl;
  for (auto p : edge) cout << color[p] + 1 << endl;

  return 0;
}
