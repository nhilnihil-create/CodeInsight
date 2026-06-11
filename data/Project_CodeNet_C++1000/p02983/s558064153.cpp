#include <bits/stdc++.h>
#define rep(i,n) for (int i = 0; i < (n); i++)
using namespace std;
typedef long long ll;
const int inf = 1001001001;

int main(){
  ll l,r;
  cin >> l >> r;

  if(r-l>3000){
    cout << 0 << endl;
    return 0;
  }


  ll ans = 2019;
  for(ll i = l; i < r; i++){
    for(ll j = l+1; j <= r; j++){
      ll di = i%2019;
      ll dj = j%2019;
      ll res = (di*dj)%2019;
      ans = min(ans, res);
    }
  }
  cout << ans << endl;  
}
