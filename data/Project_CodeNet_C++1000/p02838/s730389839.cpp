#include<bits/stdc++.h>
using namespace std;
using ll=long long;
const int mod=1e+9+7;

int main(){
  ll N;
  cin>>N;
  vector<ll>data(N);
  for(ll i=0;i<N;i++)cin>>data[i];
  ll res=0;
  for(ll d=0;d<60;d++){
    ll one=0,zero=0;
    for(ll i=0;i<N;i++){
      if((data[i]>>d)&1)one++;
      else zero++;
    }
    ll tmp=one*zero%mod;
    ll v=(1ll<<d)%mod;
    ll num=tmp*v%mod;
    res=(res+num)%mod;
  }
  cout<<res<<endl;

}