#include <bits/stdc++.h>
using namespace std;
using ll =long long;
#define all(v) v.begin(),v.end()
 
ll mod_pow(ll x,ll n,ll mod) {
ll res=1;
  while(n>0) {
if(n&1) {
res=res*x%mod;
}
   x=x*x%mod;
    n>>=1;
  }
return res;
}
 




int main() {
ll N,K;
  cin>>N>>K;
  ll mod=1000000007;
  
  vector<ll> ans(K,0);
  
  
 

for(ll i=1;i<=min(K,N-K+1);i++) {
ll S=1;
  ll A=1;
  for(ll j=0;j<i-1;j++) {
S*=(K-1-j);
    S%=mod;
  }
  
  for(ll j=2;j<=i-1;j++) {
A*=mod_pow(j,mod-2,mod);
    A%=mod;
  }
ll B=1;
ll C=1;
  for(ll j=2;j<=i;j++) {
    C*=mod_pow(j,mod-2,mod);
    C%=mod;
  }
  for(ll j=0;j<i;j++) {
B*=(N-K+1-j);
    B%=mod;
  }
  B*=C;
  B%=mod;
 S*=A;
  S%=mod;
  ans[i-1]=(S*B)%mod;
}
  
  for(ll i=0;i<K;i++) {
cout<<ans[i]<<endl;
  }
}

  
  
  
  
  
  
  
  
  