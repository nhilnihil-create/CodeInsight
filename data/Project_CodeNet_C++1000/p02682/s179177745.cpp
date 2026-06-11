#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define rep(i, ss, ee) for (int i = (ss); i < (ee); ++i)

void solve() {
  ll a, b, c, k;
  cin >> a >> b >> c >> k;
  ll ans = 0;
  if (a <= k) {
    ans += a;
    k -= a;
  } else {
    ans += k;
    k = 0;
  }
  if (b <= k) {
    k -= b;
  } else {
    k = 0;
  }
  if (c <= k) {
    ans -= c;
    k -= c ;
  } else {
    ans -= k;
    k = 0;
  }
  cout << ans << endl;
}

int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  solve();
}