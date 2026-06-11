#include<bits/stdc++.h>
#define rep(i,n) for (int i = 0; i < (int)n; ++i)
using namespace std;
using ll = long long;

int main(){
  ll l,r;
  cin >> l >> r;
  // mod 2019の場合 1 == 2020となる
  // iとjの値がi<jとなり同じにはならないため
  // 2019*2とすることでiとjが違う値が求められる
  r = min(r,l+4038);
  // mod 2019なため答えは2019より小さくなる
  int ans = 2018;
  for (ll i = l; i <= r; i++) {
    for (ll j = i+1; j <= r; j++) {
      int x = i*j%2019;
      ans = min(ans, x);
    }
  }
  cout << ans << endl;
  return 0;
}
