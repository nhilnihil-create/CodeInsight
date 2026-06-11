#include<bits/stdc++.h>

using namespace std;
using ll=long long;
#define rep(i, n) for(int i = 0; i < n; i++)
#define rep2(i, a, n) for(int i = (a); i < (n); i++)
#define chmin(mi, val) mi = min(mi, val)
#define INFL (long long)(4e18)

int main(void) {
  int L, R;
  cin >> L >> R;
  if (R - L > 2019) {
    cout << 0 << endl;
    return 0;
  }
  ll ans = INFL;
  rep2(i, L, R) {
    rep2(j, i + 1, R + 1) {
      chmin(ans, (ll)i * j % 2019);
    }
  }
  cout << ans << endl;

  return 0;
}