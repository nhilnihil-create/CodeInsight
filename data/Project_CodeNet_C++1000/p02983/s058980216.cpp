#include <bits/stdc++.h>
using namespace std;
#define ll long long
const int MOD=1e9+7;
const long double Pi=acos(-1);
using  P=pair<ll,ll>;
int main(){
  ll L,R;
  ll ans=2019;
  cin>>L>>R;
  if(R-L>=2018){cout<<0<<endl;return 0;}
  else{
    for(ll i=L;i<=R-1;i++){
      for(ll j=i+1;j<=R;j++){
        ll a=i%2019;
        ll b=j%2019;
        ll c=(a*b)%2019;
        ans=min(ans,c);
      }
    }
  }
  cout<<ans<<endl;
}