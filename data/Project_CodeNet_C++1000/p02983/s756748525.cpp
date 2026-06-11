#include <bits/stdc++.h>
#define rep(i,cc,n) for(ll i=cc;i<=n;++i)
using namespace std;
using ll = long long;

int main() {
  int L, R;
  cin >> L >> R;

  ll ans = 2020;
  if (2020 < R - L) ans = 0;
  else {
    rep(i,L,R) {
      rep(j,i+1,R) {
        ans = min(ans, i * j % 2019);
      }
    }
  }
  
  cout << ans << endl;
  return 0;
}
