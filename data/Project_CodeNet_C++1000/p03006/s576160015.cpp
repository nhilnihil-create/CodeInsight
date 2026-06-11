#include <bits/stdc++.h>
#define rep(i,n) for (int i = 0; i < (n); ++i)
using namespace std;
using ll = long long;
using P = pair<int,int>;

int main() {
  int n;
  cin >> n;
  vector<int> x(n), y(n);
  rep(i, n) cin >> x[i] >> y[i];

  set<P> ball;
  rep(i, n) ball.insert(make_pair(x[i], y[i]));

  int ans = n;
  rep(i, n) rep(j, n) {
    if (i >= j) continue;
    int p = x[j] - x[i];
    int q = y[j] - y[i];
    map<P, bool> visited;
    int cost = 0;
    rep(k, n) {
      if (visited[make_pair(x[k], y[k])]) continue;
      visited[make_pair(x[k], y[k])] = true;
      int t = 1;
      while (1) {
        P to = make_pair(x[k] + t*p, y[k] + t*q);
        if (ball.find(to) == ball.end()) break;
        visited[to] = true;
        ++t;
      }
      t = -1;
      while (1) {
        P to = make_pair(x[k] + t*p, y[k] + t*q);
        if (ball.find(to) == ball.end()) break;
        visited[to] = true;
        --t;
      }
      ++cost;
    }
    ans = min(ans, cost);
  }
  cout << ans << endl;
  return 0;
}