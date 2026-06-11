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
  ll mod=1000000007;
 string S;
  cin>>S;
  ll N=S.size();
  vector<ll> vec(N);
  
  ll count=1;
  vec[0]=1;
  for(ll i=1;i<N;i++) {
count*=10;
    count%=13;
    vec[i]=count;
  }
  
  reverse(all(vec));
  

  vector<vector<ll>> dp(N+1,vector<ll> (13,0));
  dp[0][0]=1;
  for(ll i=1;i<=N;i++) {
if(S[i-1]!='?') {
  ll a=vec[i-1]*(S[i-1]-'0');
  a%=13;
  
  for(ll j=0;j<13;j++) {
    if(a+j>12) {
a-=13;
    }
dp[i][a+j]+=dp[i-1][j];
    dp[i][a+j]%=mod;
  }
}
    else {
for(ll j=0;j<10;j++) {
ll a=vec[i-1]*j;
  a%=13;
  for(ll h=0;h<13;h++) {
if(a+h>12) {
a-=13;
}
    dp[i][a+h]+=dp[i-1][h];
    dp[i][a+h]%=mod;
  }
}
    }
    
  }

 
cout<<dp[N][5]<<endl;
}

  
  
  
  
  