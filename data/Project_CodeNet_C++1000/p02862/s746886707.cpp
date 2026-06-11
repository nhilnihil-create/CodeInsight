#include <bits/stdc++.h>
using namespace std;
#include<cstdlib>

#define rep(i,n) for(int (i)=0;(i)<(n);(i)++)
typedef long long ll;

ll gyaku(ll a);
ll d = pow(10, 9) + 7;

int main(){
  ll x, y;
  cin >> x >> y;

  if((2*y-x)%3!=0 || (2*x-y)%3!=0 ||(2*x-y)<0||(2*y-x)<0) cout << 0;
  else{
    ll a=(2*y-x)/3, b=(2*x-y)/3;
    ll ans = 1;
    for(ll i=0; i<a; i++){
      ans = ans * (a+b-i);
      //cout << ans << endl;
      if(ans>d) ans = ans%d;
      ans = ans * (gyaku(a-i)%d);
      if(ans>d) ans = ans%d;
    }
    if(ans>d) ans = ans%d;
    cout << ans;
  }
}

ll gyaku(ll a){
  ll x=1;
  ll di = d-2;

  while(di>0){
    if(di&1) x *= a;
    a  = a * a % d;
    if(x>d) x=x%d;
    di >>= 1;
  }
  return x;
}