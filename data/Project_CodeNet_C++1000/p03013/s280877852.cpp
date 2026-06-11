#include <bits/stdc++.h>  
using namespace std;
using ll = long long int;
#define rep(i,n) for(int i=0; i<(int)(n); i++)

int p=1000000007;
ll f(ll x){
  if(x==0){return 1;}
  if(x==1){return 1;}
  ll a=1, b=1, c=0;
  rep(i,x-1){
    c=(a+b)%p;
    a=b;b=c;
  }
  return c;
}
int main() {
  ll n,m,ans=1; cin>>n>>m;
  vector<ll> v(m);
  rep(i,m){
    cin>>v[i];
    if(i!=0){if(v[i]==v[i-1]+1){ans=0;break;}}
  }
  if(m==0){cout<<f(n);}
  else if(ans==0){cout<<0<<endl;}
  else{
    if(v[0]!=1){ans*=f(v[0]-1)%p;ans%=p;}
    for(int i=0; i<m-1;  i++){ans*=f(v[i+1]-v[i]-2)%p;ans%=p;}
    ans*=f(n-1-v[m-1])%p;ans%=p;
    cout<<ans<<endl;
  } 
  
}

