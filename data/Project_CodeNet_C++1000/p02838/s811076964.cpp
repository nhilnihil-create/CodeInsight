#include <bits/stdc++.h>
using namespace std;
#define ll long long
const ll MOD=1e9+7;
int main(){
  ll N,ans=0,x=1;
  cin>>N;
  vector<ll> vec(61);
  for(ll i=0;i<N;++i){
    ll a,j=0;
    cin>>a;
    while(a>0){
      if(a&1){++vec.at(j);}
      a/=2;
      ++j;
    }
  }
  for(int i=0;i<61;++i){
    ans+=((((N-vec.at(i))*vec.at(i))%MOD)*(x%MOD))%MOD;
    x*=2;
    ans%=MOD;
  }
  cout<<ans<<endl;
}