#include <bits/stdc++.h>
#include <numeric>
#define rep(i,n) for (int i = 0; i < n; ++i)
#define rep1(i,n) for (int i = 1; i <= n; ++i)
template<typename T> inline bool chmin(T& a, T b) { if (a > b) { a = b; return 1; } return 0; }
template<typename T> inline bool chmax(T& a, T b) { if (a < b) { a = b; return 1; } return 0; }
template<typename T> inline T intceil(T a, T b) { return (a + (b - 1)) / b; }
using namespace std;
typedef long long ll;
typedef long double ld;
typedef pair<int,int> P;
const long long MOD = 1e9+7;
#define precout(val) cout << std::fixed << std::setprecision(20) << val;
const string alphabet = "abcdefghijklmnopqrstuvwxyz";
const int dy[4] = { 0, 1, 0, -1 };
const int dx[4] = { 1, 0, -1, 0 };
static const double pi = 3.141592653589793;

int main() {
  cin.tie(0);
  ios::sync_with_stdio(false);

  int n; cin >> n;
  if(n == 1) {
    cout << 1 << endl;
    return 0;
  }

  vector<int> x(n), y(n);
  rep(i, n) {
    cin >> x[i] >> y[i];
  }

  map<P, int> cnt;
  rep(k, n) {
    rep(l, n) {
      if(k == l) continue;
      ++cnt[make_pair(x[l] - x[k], y[l] - y[k])];
    }
  }

  int ans = n;
  rep(i, n) {
    rep(j, n) {
      if(i == j) continue;
      int dx = x[j] - x[i], dy = y[j] - y[i];

      chmin(ans, n - cnt[make_pair(dx, dy)]);
    }
  }

  cout << ans << endl;
}
