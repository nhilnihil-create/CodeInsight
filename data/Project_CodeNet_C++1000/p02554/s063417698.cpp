#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define P pair<ll,ll>

const int MOD=1e9+7;

int main(){
  int n;
  cin>>n;
  ll u=1,a=1,b=1; 
  rep(i,n){
    u*=10; a*=9; b*=8;
    u%=MOD; a%=MOD; b%=MOD;
  }
  ll ans=u-(a*2-b);
  ans%=MOD;
  if(ans<0) ans+=MOD;
  cout<<ans<<endl;
}