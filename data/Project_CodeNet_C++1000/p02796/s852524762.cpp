#include <bits/stdc++.h>
#define rep(i, n) for (int i = 0; i < int(n); i++)
using namespace std;
using ll = long long;
const int INF = (1<<30)-1;
const long long LINF = (1LL<<62)-1;
const int dx[] = {-1, 0, 1, 0};
const int dy[] = {0, 1, 0, -1};
template<class T> inline bool chmax(T& a, T b) { if (a < b) { a = b; return true; } return false; }
template<class T> inline bool chmin(T& a, T b) { if (a > b) { a = b; return true; } return false; }

signed main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  int n;
  cin >> n;
  vector<pair<int, int>> a(n);
  rep(i, n) {
    int x, l;
    cin >> x >> l;
    a[i] = {x-l, x+l};
  }
  sort(a.begin(), a.end(), [](auto x, auto y) {
    if (x.second == y.second)
      x.first > y.first;
    return x.second < y.second;
  });
  int r = -INF, ans = 0;
  rep(i, n) {
    if (r <= a[i].first) {
      ans++;
      r = a[i].second;
    }
  }
  cout << ans << endl;
  return 0;
}