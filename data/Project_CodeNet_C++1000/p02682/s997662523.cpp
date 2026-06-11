#include <bits/stdc++.h>
using namespace std;

template<typename T> void drop(const T &x){cout<<x<<'\n';exit(0);}

void solve() {
  int a, b, c, k;
  cin >> a >> b >> c >> k;

  if(a >= k) drop(k);
  k -= a;
  if(b >= k) drop(a);
  k -= b;
  cout << a-k << '\n';
}

signed main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  int T=1;
  //cin >> T;
  while(T--) solve();

  return 0;
}
