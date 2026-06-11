#include <bits/stdc++.h>
#define rep(i,n) for (int i = 0; i < (n); ++i)
using namespace std;
using ll = long long;
using P = pair<int,int>;

int main() {
  int n;
  cin >> n;
  vector<ll> a(n);
  rep(i, n) cin >> a[i];
  ll l = 0;
  rep(i, n) l += a[i];
  ll c = 0;
  ll ans = l;
  rep(i, n) {
    c += a[i];
    ans = min(ans, abs(l - 2 * c));
  }
  cout << ans << endl;
  return 0;
}