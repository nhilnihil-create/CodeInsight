#include<bits/stdc++.h>
using namespace std;
using ll=long long;
const ll MOD=1000000007;
int main(){
  ll n;
  cin>>n;
  vector<ll>data(n);
  for(ll i=0;i<n;i++)cin>>data[i];
  ll ans=0;
  for(ll d=0;d<60;d++){
    ll one=0;
    ll zero=0;
    for(ll i=0;i<n;i++){
      if((data[i]>>d)&1)one++;
      else zero++;
    }
    ll tmp=(1ll<<d)%MOD;
    //cout<<tmp<<endl;
    ll pr=one*zero%MOD;
    pr=pr*tmp%MOD;
    ans=(ans+pr)%MOD;

  }
  cout<<ans<<endl;
}