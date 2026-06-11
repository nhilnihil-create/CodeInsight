#include <bits/stdc++.h>
#define rep(i, n) for (ll i = 0; i < (n); i++)
using namespace std;
using ll = long long;
const ll INF = 1LL << 60;

int main(void) {
  int n, m;
  cin >> n >> m;
  vector<pair<int, int>> p(m);
  rep(i, m) cin >> p[i].first >> p[i].second;
  rep(x, 1000) {
    int digit = 1;
    int nx = x / 10;
    vector<int> d(1, x % 10);
    while (nx) {
      digit++;
      d.push_back(nx % 10);
      nx /= 10;
    }
    if (digit != n) continue;
    bool ok = true;
    reverse(d.begin(), d.end());
    rep(i, m) {
      if (d[p[i].first - 1] != p[i].second) ok = false;
    }
    if (ok) {
      cout << x << '\n';
      return 0;
    }
  }
  cout << -1 << '\n';
  return 0;
}