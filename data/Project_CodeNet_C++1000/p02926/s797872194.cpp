#include <bits/stdc++.h>
#define rep(i, n) for (int i = 0; i < (n); i++)
using namespace std;
using ll = long long;
const int INF = (1<<30)-1;
const long long LINF = (1LL<<62)-1;
const int dx[] = {-1, 0, 1, 0};
const int dy[] = {0, 1, 0, -1};
template<class T> inline bool chmax(T& a, T b) { if (a < b) { a = b; return true; } return false; }
template<class T> inline bool chmin(T& a, T b) { if (a > b) { a = b; return true; } return false; }

using T = tuple<long double, int, int>;

signed main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  int n;
  cin >> n;
  vector<int> x(n), y(n);
  rep(i, n) cin >> x[i] >> y[i];
  vector<T> p;
  rep(i, n) {
    long double rad = atan2(y[i], x[i]);
    p.emplace_back(rad, x[i], y[i]);
  }
  sort(p.begin(), p.end());
  long double ans = 0;
  for (int i = 0; i < n; i++) {
    long double vx = 0, vy = 0;
    rep(j, n) {
      vx += get<1>(p[(i+j)%n]);
      vy += get<2>(p[(i+j)%n]);
      chmax(ans, sqrt(vx*vx+vy*vy));
    }
  }
  cout << fixed << setprecision(15) << ans << endl;
  return 0;
}