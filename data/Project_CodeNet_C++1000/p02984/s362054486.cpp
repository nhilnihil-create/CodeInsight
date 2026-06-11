#include <bits/stdc++.h>
#define rep(i, n) for (int i = 0; i < (n); ++i)
using namespace std;
using ll = long long;
using P = pair<int, int>;

int main() {
  int n;
  cin >> n;
  vector<int> d(n);
  rep(i, n) cin >> d[i];
  ll ans = 0;
  rep(i, n) {
    if (i%2 == 0) ans += d[i];
    else ans -= d[i];
  }
  rep(i, n) {
    cout << ans << ' ';
    ans = (d[i] - ans/2) * 2;
  }
  return 0;
}