#include <bits/stdc++.h>
using namespace std;

template<typename T> void drop(const T &x){cout<<x<<'\n';exit(0);}

void solve() {
  int n;
  cin >> n;
  long long ans = 1;
  vector<long long> a(n);
  for(int i = 0; i < n; ++i) {
    cin >> a[i];
    if(a[i] == 0) drop(0);
  }
  for(int i = 0; i < n; ++i) {
    if(a[i] <= 1000000000000000000/ans) ans *= a[i];
    else drop(-1);
  }
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
