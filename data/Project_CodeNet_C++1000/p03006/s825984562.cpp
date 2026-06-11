#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for (int i = 0; i < (int)n; ++i)
#define repi(i, a, b) for (int i = int(a); i < int(b); ++i)
#define repr(i, n) for (int i = (int)n - 1; i >= 0; --i)
#define ALL(a) (a).begin(), (a).end()
using ll = long long;
using Graph = vector<vector<int>>;
const ll mod = 1e9 + 7;
const ll INF = 1e9;

int main() {
  int n;
  cin >> n;
  vector<pair<int, int>> p(n);
  rep(i, n) {
    int x, y;
    cin >> x >> y;
    p[i] = make_pair(x, y);
  }
  map<pair<int, int>, int> mp;
  rep(i, n) rep(j, n) {
    if (i == j) continue;
    int xdist, ydist;
    xdist = p[j].first - p[i].first;
    ydist = p[j].second - p[i].second;
    pair<int, int> a = make_pair(xdist, ydist);
    mp[a]++;
  }
  int cnt = 0;
  for (auto x : mp) {
    cnt = max(cnt, x.second);
  }
  cout << n - cnt << endl;
  return 0;
}
