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
#define SIZE(a) ll((a).size())
#define out(a) cout<<(a)<<endl;
const int inf=INT_MAX;
const int MAX = 510000;
const ll MOD = 998244353;


int main(){
  ll n;cin>>n;
  vll x(n),y(n);
  rep(i,0,n){
    cin>>x[i]>>y[i];
  }
  map<P,ll> m;
  rep(i,0,n){
    rep(j,i+1,n){
      m[make_pair(x[i]-x[j],y[i]-y[j])]++;
      m[make_pair(x[j]-x[i],y[j]-y[i])]++;
    }
  }
  ll ans=0;
  for(auto u:m){
    ans=max(ans,u.second);
  }
  cout<<n-ans<<endl;
}


