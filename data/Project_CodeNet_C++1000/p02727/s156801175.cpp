#include <bits/stdc++.h>
#define rep(i,n) for (int i = 0; i < (n); ++i)
using namespace std;
using ll = long long;
using P = pair<int,int>;

int main() {
  int x, y, a, b, c;
  cin >> x >> y >> a >> b >> c;
  vector<P> d;
  rep(i, a) {
    int p;
    cin >> p;
    d.push_back(make_pair(-p, 1));
  }
  rep(i, b) {
    int q;
    cin >> q;
    d.push_back(make_pair(-q, 2));
  }
  rep(i, c) {
    int r;
    cin >> r;
    d.push_back(make_pair(-r, 3));
  }
  sort(d.begin(), d.end());

  ll ans = 0;
  int a0 = 0, b0 = 0, c0 = 0;
  rep(i, d.size()) {
    if (a0 + b0 + c0 == x + y) break;
    int clr = d[i].second;
    if (clr == 1 && a0 == x) continue;
    if (clr == 2 && b0 == y) continue;
    ans -= d[i].first;
    if (clr == 1) ++a0;
    if (clr == 2) ++b0;
    if (clr == 3) ++c0;
  }
  cout << ans << endl;
  return 0;
}