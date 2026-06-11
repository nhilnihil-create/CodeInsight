#include<bits/stdc++.h>
using namespace std;
using ll=long long;
const ll MOD=1000000007;
int main(){
  ll N,K;
  cin>>N>>K;
  ll ans=0;
  for(ll i=K;i<=N+1;i++){
    ll low=i*(i-1)/2;
    ll high=i*(2*N-i+1)/2;
    ll tmp=high-low+1;
    ans=(ans+tmp)%MOD;
  }
  cout<<ans<<endl;
}