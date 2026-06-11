#include <bits/stdc++.h>
using namespace std;

template<typename T> void drop(const T &x){cout<<x<<'\n';exit(0);}

void solve() {
  int n;
  cin >> n;
  int ans = 0;
  for(int i=1; i<=n; ++i) {
    int a = i;
    int count = 0;
    while(a) {
      a /= 10; ++count;
    }
    if(count%2) ans++;
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
