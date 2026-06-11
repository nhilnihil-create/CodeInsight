#include <bits/stdc++.h>
using namespace std;

template<typename T> void drop(const T &x){cout<<x<<'\n';exit(0);}

void solve() {
  int a, b, c, k;
  cin >> a >> b >> c >> k;

  int x, y, z;
  y = a;
  x = k-a;
  z = x-b;
  if(a >= k) drop(k);
  if(b >= x) drop(y);
  cout << y-z << '\n';
}

signed main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  int T=1;
  //cin >> T;
  while(T--) solve();

  return 0;
}
