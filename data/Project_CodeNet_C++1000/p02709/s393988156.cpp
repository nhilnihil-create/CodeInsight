
#include <bits/stdc++.h>
#define rep(i, n) for (int i = 0; i < (n); ++i)
#define rrep(i, n) for (int i = 1; i <= (n); ++i)
#define drep(i, n) for (int i = (n)-1; i >= 0; --i)
using namespace std;
typedef long long ll;
typedef pair<ll, ll> PI;
typedef vector<ll> VI;
typedef vector<VI> VVI;
typedef vector<PI> VPI;

int main() {
  int n;
  cin >> n;
  VPI a(n);
  rep(i, n) {
    ll ae;
    cin >> ae;
    a.emplace_back(ae, (ll)i);
  }
  sort(a.begin(), a.end(), greater<PI>());
  VVI dp(n + 1, VI(n + 1));

  rrep(xy, n) {
    rep(x, xy + 1) {
      int y = xy - x;
      ll left = abs(a.at(xy - 1).second - x + 1) * a.at(xy - 1).first;
      ll right = abs(n - y - a.at(xy - 1).second) * a.at(xy - 1).first;
      if (0 < x && x != xy) {
        dp.at(xy).at(x) =
            max(dp.at(xy - 1).at(x - 1) + left, dp.at(xy - 1).at(x) + right);
      } else if (x == 0) {
        dp.at(xy).at(x) = dp.at(xy - 1).at(x) + right;
      }
      if (x == xy) {
        dp.at(xy).at(x) = dp.at(xy - 1).at(x - 1) + left;
      }
    }
  }
  ll ans = 0;
  rep(x, n + 1) { ans = max(ans, dp.at(n).at(x)); }
  cout << ans << endl;
  return 0;
}
