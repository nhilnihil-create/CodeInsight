#include <bits/stdc++.h>
using namespace std;

template<typename T> void drop(const T &x){cout<<x<<'\n';exit(0);}

void solve() {
  int a, b, c, k;
  cin >> a >> b >> c >> k;

  int tmp = min(a, k);
  int ans = tmp;
  k -= tmp;
  if(!k) drop(ans);
  tmp = min(b, k);
  k -= tmp;
  if(!k) drop(ans);
  tmp = min(c, k);
  ans -= tmp;
  cout << ans << '\n';
}

signed main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  int T=1;
  //cin >> T;
  while(T--) solve();

  return 0;
}
