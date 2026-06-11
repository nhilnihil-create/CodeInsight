#include <bits/stdc++.h>
#define rep(i, n) for (int i = 0; i < (int)(n); i++)

using namespace std;
using ll = long long;

int main() {
  int n;
  cin >> n;
  vector<int> as(n + 1), bs(n);
  rep(i, n + 1) cin >> as[i];
  rep(i, n) cin >> bs[i];
  ll ans = 0;
  rep(i, n) {
    ll l = min(as[i], bs[i]);
    ans += l;
    as[i] -= l;
    bs[i] -= l;
    ll r = min(bs[i], as[i + 1]);
    ans += r;
    bs[i] -= r;
    as[i + 1] -= r;
  }
  cout << ans << endl;
  return 0;
}
