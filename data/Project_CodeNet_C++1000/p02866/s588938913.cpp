#include <bits/stdc++.h>
#define ll long long
using namespace std;
const ll MOD=998244353;

ll modpow(ll x,ll y){
  long long ans=1;
  while(y>0){
    if(y&1){
      ans*=x%MOD;
    }
    x*=x%MOD;
    x%=MOD;
    ans%=MOD;
    y>>=1;
  }
  return ans;
}

int main() {
  ll N;
  
  cin>>N;
  ll D[N+10];
  for(int i=0;i<N+10;i++){
    D[i]=0;
  }
  ll as;
  for(int i=0;i<N;i++){
    ll a;
    cin>>a;
    D[a]++;
    if(i==0){
      as=a;
    }
  }
  ll ans=1;
  ll cnt=1;
  for(int i=1;i<N+10;i++){
    if(D[i-1]==0){
      break;
    }
    ans*=modpow(D[i-1],D[i]);
    ans%=MOD;
    cnt+=D[i];
  }
  if(cnt!=N||as!=0||D[0]!=1){
    ans=0;
  }
  cout<<ans;
  return 0;
}
