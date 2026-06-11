#include <bits/stdc++.h>
#define rep(i,n) for (int i = 0; i < (n); ++i)
using namespace std;
using ll = long long;
using P = pair<int,int>;

int main() {
  int n;
  cin >> n;
  vector<int> a(n+1);
  rep(i, n+1) cin >> a[i];

  vector<ll> cum(n+1);
  cum[n] = a[n];
  for (int i = n-1; i >= 0; i--) {
    cum[i] = a[i] + cum[i+1];
  }

  ll nd = 1;
  ll ans = 0;
  rep(i, n+1) {
    if (nd < a[i]) {
      ans = -1;
      break;
    }
    ans += nd;
    nd -= a[i];
    if (i < n) nd = min(2*nd, cum[i+1]);
    // printf("ans = %lld, nd = %lld\n", ans, nd);
  }
  cout << ans << endl;
  return 0;
}