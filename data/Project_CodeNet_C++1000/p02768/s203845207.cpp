#include<bits/stdc++.h>
using namespace std;
#define arep(i,x,n) for(int i=int(x);i<(int)(n);i++)
#define rep(i,n) for(long long i = 0;i < n;++i)
#define pi 3.141592653589793
#define eps 0.00000001
#define INF 1e9+7  
using ll = long long; 
using P=pair<int,int>;
using lP=pair<ll,ll>;
using fP=pair<double,double>;
ll const mod=1e9+7;
const ll MAX=300000;
ll modpow(ll a,ll b){
  ll r=1;
  while(b>0){
    if(b%2==1)(r*=a)%=mod;
    (a*=a)%=mod;
    b/=2;
  }
  return r;
}
ll chose(ll a,ll b){
  if(b==0||b==a)return 1;
  if(b==1||b+1==a)return a;
  ll x=a,y=b;
  while(y>1){
    (a*=(--x))%=mod;
    (b*=(--y))%=mod;
  }
  return a*modpow(b,mod-2)%mod;
}

int main(){
    int n,a,b;
    cin>>n>>a>>b;
    ll ans=0;
    ans=modpow(2,n)-1;
    //cout<<ans<<endl;
    ans-=chose(n,a);
    //cout<<ans<<endl;
    if(a!=b)ans-=chose(n,b);
    if(ans<0)ans+=mod;
    if(ans<0)ans+=mod;
    cout<<ans<<endl;
    
    return 0;
}
