#include <bits/stdc++.h>
#define rep(i, n) for (int i = 0; i < (int)(n); i++)

using namespace std;
using ll = long long;

int main() {
  int n, q;
  cin >> n >> q;
  vector<vector<int> > graph(n);
  rep(i, n - 1) {
    int a, b;
    cin >> a >> b;
    a--;
    b--;
    graph[a].push_back(b);
    graph[b].push_back(a);
  }
  vector<ll> cnts(n, 0);
  rep(i, q) {
    int p, x;
    cin >> p >> x;
    p--;
    cnts[p] += x;
  }
  vector<bool> visited(n, false);
  queue<int> que;
  que.push(0);
  while (!que.empty()) {
    int v = que.front();
    que.pop();
    visited[v] = true;
    for (auto nv : graph[v]) {
      if (visited[nv]) {
        continue;
      }
      cnts[nv] += cnts[v];
      que.push(nv);
    }
  }
  rep(i, n) {
    if (i == n - 1) {
      cout << cnts[i] << endl;
    } else {
      cout << cnts[i] << " ";
    }
  }
  return 0;
}
