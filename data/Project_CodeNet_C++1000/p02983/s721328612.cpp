#include <bits/stdc++.h>
#define rep(i,n) for(int i=0;i<(int)(n);i++)
using namespace std;

using ll = long long;

const int INF = 1001001001;
const ll INF_LL = 1001001001001001001LL;

int main(void){
  ll l,r; cin >> l >> r;

  r = min(r,l+2019);

  ll mod = 2019;
  ll ans = INF_LL;
  for(ll i = l;i<=r;i++){
    for(ll j = i+1;j<=r;j++){
      if(i>=j) continue;
      
      ll tmp = i*j;
      tmp %= mod;
      ans = min(ans,tmp);
    }
  }

  cout << ans << endl;
  
  return 0;
}
