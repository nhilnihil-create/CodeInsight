#include <bits/stdc++.h>
#define rep(i,n) for (int i = 0; i < (n); ++i)
using namespace std;
using ll = long long;
using P = pair<int,int>;

const int INF = 1e9;

int main() {
  int n, x, y;
  cin >> n >> x >> y;
  --x;
  --y;

  vector<vector<int>> g(n);
  rep(i, n-1) {
    g[i].push_back(i+1);
    g[i+1].push_back(i);
  }
  g[x].push_back(y);
  g[y].push_back(x);

  vector<vector<int>> d(n, vector<int>(n, INF));
  queue<int> Q;

  rep(i, n) {
    d[i][i] = 0;
    Q.push(i);
    while (Q.size()) {
      int pos = Q.front();
      Q.pop();
      rep(j, g[pos].size()) {
        int to = g[pos][j];
        if (d[i][to] <= d[i][pos] + 1) continue;
        d[i][to] = d[i][pos] + 1;
        Q.push(to);
      }
    }
  }

  vector<int> res(n, 0);
  rep(i, n) rep(j, n) {
    if (i >= j) continue;
    ++res[d[i][j]];
  }
  for (int i = 1; i < n; ++i) cout << res[i] << endl;
  return 0;
}