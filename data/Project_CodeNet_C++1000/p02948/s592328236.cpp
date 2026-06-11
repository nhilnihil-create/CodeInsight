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
ll roundd(ll x,ll n){
  if(x>n){return x%n;}
  else if(x<0){return x%n+n;}
  else return x;
}

int main(){
  ll n,m;cin>>n>>m;
  priority_queue<ll> q;
  vvll ok(100001);
  rep(i,0,n){
    ll a,b;cin>>a>>b;
    ok[a].push_back(b);
  }
  ll ans=0;
  rep(i,1,m+1){
    for(auto u:ok[i])q.push(u);
    if(!q.empty()){
      ll t=q.top();
      ans+=t;
      q.pop();
    }
  }
  cout<<ans<<endl;
}

