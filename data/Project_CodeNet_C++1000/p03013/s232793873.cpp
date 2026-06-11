#include<bits/stdc++.h>
using namespace std;
using ll=int64_t;

ll mod=1000000007;

ll f(ll x,vector<ll>&dp){
  if(x==1){
    dp.at(x)=1;
    return dp.at(x);
  }
  else if(x==2){
    dp.at(x)=2;
    return dp.at(x);
  }
  if(dp.at(x)!=0){
    return dp.at(x);
  }
  else{
    dp.at(x)=(f(x-2,dp)%mod+f(x-1,dp)%mod)%mod;
    return dp.at(x);
  }
}

int main(){
  ll n,m;cin>>n>>m;
  vector<ll>dp(n+1,0);
  if(m==0){
    cout <<f(n,dp)<<endl;
    return 0;
  }
  vector<ll>a(m);
  cin>>a.at(0);
  for(ll i=1;i<m;i++){
    cin>>a.at(i);
    if(a.at(i)-a.at(i-1)==1){
      cout <<0<<endl;
      return 0;
    }
  }
  vector<ll>s(m+1,0);
  if(m==1){
    s.at(0)=a.at(0)-1;
    s.at(1)=n-a.at(0)-1;
  }
  else{
    for(ll i=0;i<m;i++){
      if(i==0){
        s.at(i)=a.at(i)-1;
      }
      else {
        s.at(i)=a.at(i)-a.at(i-1)-2;
      }
    }
    s.at(m)=n-a.at(m-1)-1;
  }
  ll ans=1;
  for(ll i=0;i<m+1;i++){
    if(s.at(i)==0)continue;
    ans*=f(s.at(i),dp);
    ans%=mod;
  }
  cout <<ans<<endl;
}