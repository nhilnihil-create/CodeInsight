#include <bits/stdc++.h>
#define rep(i, a, n) for (int i = a; i < n; i++)
#define repr(i, a, n) for (int i = n - 1; i >= a; i--)
using namespace std;
using ll = long long;
using P = pair<int, int>;
template <typename T> void chmin(T &a, T b) { a = min(a, b); }
template <typename T> void chmax(T &a, T b) { a = max(a, b); }
 
int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
 
  int n, x, y;
  cin >> n >> x >> y;
  x--, y--;
 
  vector<vector<int>> G(n);
  G[x].push_back(y);
  G[y].push_back(x);
 
  rep(i, 0, n - 1) {
    G[i].push_back(i + 1);
    G[i + 1].push_back(i);
  }
 
  vector<int> ans(n - 1, 0);
 
  rep(i, 0, n) {
    queue<int> q;
    vector<int> root(n, 1e9);
    q.push(i);
    root[i] = 0;
    while (!q.empty()) {
      int t = q.front();
      q.pop();
      for (auto g : G[t]) {
        if (root[g] != 1e9)
          continue;
        chmin(root[g], root[t] + 1);
        q.push(g);
      }
    }
 
    rep(j, i + 1, n) { ans[root[j] - 1]++; }
  }
 
  rep(i, 0, n - 1) cout << ans[i] << endl;
}