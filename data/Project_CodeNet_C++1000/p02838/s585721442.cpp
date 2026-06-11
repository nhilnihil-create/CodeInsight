#include<bits/stdc++.h>
using namespace std;
using ll=long long;
const ll MOD=1000000007;
int main(){
  ll N;
  cin>>N;
  ll res=0;
  vector<ll>data(N);
  for(ll i=0;i<N;i++)cin>>data[i];
  for(ll d=0;d<60;d++){
    ll zero=0,one=0;
    for(ll i=0;i<N;i++){
      if(data[i]>>d&1)one++;
      else zero++;
    }
    ll tmp=(1LL<<d)%MOD;
    ll ans=(zero*one)%MOD*tmp%MOD;
    res=(res+ans)%MOD;
  }
  while(res<0)res+=MOD;
  res=res%MOD;
  cout<<res<<endl;
}