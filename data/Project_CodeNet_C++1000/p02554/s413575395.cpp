#include <bits/stdc++.h>
#define rep(i,n) for(int i=0;i<(int)(n);i++)
using namespace std;

using ll = long long;

const int INF = 1001001001;
const ll INF_LL = 1001001001001001001LL;

int main(void){
  int n; cin >> n;
  ll div = 1e9;
  div += 7;

  ll ans;
  ll p10 = 1,p9 = 1,p8 = 1;
  rep(i,n){
    p10 *= 10;
    p9 *= 9;
    p8 *= 8;
    p10 %= div;
    p9 %= div;
    p8 %= div;
  }
  p9 *= 2;
  p9 %= div;

  ans = p10-p9+p8;
  ans %= div;
  ans = (ans+div)%div;
  cout << ans << endl;
  
  return 0;
}
