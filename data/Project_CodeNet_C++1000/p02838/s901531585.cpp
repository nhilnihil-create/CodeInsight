#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)

const int MOD=1000000007;

int main(){
  int n;
  cin>>n;
  vector<ll> a(n);
  rep(i,n) cin>>a[i];
  ll ans=0;
  rep(i,60){
    ll X=0, Y=0;
    rep(j,n){
      if((a[j]>>i)&1){
        X++;
      }else{
        Y++;
      }
    }
    ll now=X*Y%MOD;
    rep(j,i){
      now=now*2%MOD;
    }
    ans+=now;
    ans%=MOD;
  }
  cout<<ans<<endl;
}
