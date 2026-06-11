#include "bits/stdc++.h"
#include "math.h"
 
using namespace std;
typedef long long ll;
typedef vector<ll> vll;
typedef vector<vll> vvll;
typedef vector<bool> vb;
typedef vector<vb> vvb;
typedef vector<int> vin;
typedef pair<ll,ll> P;
typedef vector<P> vp;
#define rep(i,a,b) for(ll i=(a);i<(b);++i)
#define drep(i,a,b) for(ll i=(a);i>=(b);--i)
#define SIZE(a) int((a).size())
#define out(a) cout<<(a)<<endl;
const int INF=INT_MAX;
const int MAX = 510000;
const ll MOD = 1000000007;
ll fac[MAX], finv[MAX], inv[MAX];


int main(){
  ll n,m;cin>>n>>m;
  vll c(n,-1);
  bool ok=false;
  rep(i,0,m){
    ll s,a;cin>>s>>a;
    if(c[s-1]!=-1&&c[s-1]!=a){
      ok=true;break;
    }
    else{
      c[s-1]=a;
    }
  }
  if(n!=1&&c[0]==0)ok=true;
  if(n!=1&&c[0]==-1){c[0]=1;}
  if(ok){cout<<-1<<endl;}
  else{
    ll ans=0;
    rep(i,0,n){
      if(c[i]!=-1)ans+=c[i]*pow(10,n-1-i);
      
    }
    cout<<ans<<endl;
  }
}




