#include <bits/stdc++.h>
using namespace std;
using ll=long long;
ll mod =1000000007;
#define rep(i,n) for(int i=0;i<n;i++)

ll exp(ll a,ll n){
  if(n==0) return 1;
  else if(n%2==0) return (exp(a,n/2)*exp(a,n/2))%mod;
  else return (a*exp(a,n-1))%mod;
}

int main() {
  ll x,y;
  cin>>x>>y;
  ll ans;
  ll a=2*y-x;
  ll b=2*x-y;
  if((a>=0 && a%3==0) && (b>=0 && b%3==0)){
    a/=3;
    b/=3;
    ll p=1;
    ll q=1;
    for(int i=0;i<b;i++){
      p*=a+b-i;
      p%=mod;
      q*=i+1;
      q%=mod;
    }
    ll qq=exp(q,mod-2);
    ans=p*qq;
    ans%=mod;
  }
  else ans=0;
  cout<<ans<<endl;
}