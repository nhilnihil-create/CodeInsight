#include <bits/stdc++.h>
typedef long long ll;
using namespace std;
const ll MOD = 1e9+7;

ll q_pow(ll a, ll b) {
  ll res = 1;
  while(b>0) {
    if(b&1) (res*=a)%=MOD;
    (a*=a)%=MOD;
    b>>=1;
  }
  return res;
}

int main() {
  ll x,y; cin>>x>>y;
  ll ans;
  // ナイトの動き方はi,jの合計値が3の倍数になるように動く
  // かつx,yうち大きいほうが小さいほうの2倍以内でなければならない
  if((x+y)%3!=0) ans=0;
  else {
    if(max(x,y)>min(x,y)*2) ans=0;
    else {
      // 答えが存在するのであれば、移動の合計回数は求められる
      int numMove = (x+y)/3;
      int numMove12 = 2*numMove-x;
      // (1,2)で移動する回数を、移動合計回数の組み合わせで考えれば良い
      // n!
      ll fac=1;
      vector<ll> inv(numMove+1);
      for(int i=1; i<=numMove; i++) (fac*=i)%=MOD;
      inv[numMove]=q_pow(fac,MOD-2);
      for(int i=numMove-1; i>=0; i--) inv[i]=inv[i+1]*(i+1)%MOD;
      ans = (fac*inv[numMove-numMove12])%MOD*inv[numMove12]%MOD;
    }
  }
  cout << ans << endl;
}
