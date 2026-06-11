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
  ll n;cin>>n;
  vvll g(10,vll(10,0));
  rep(i,1,n+1){
    string s=to_string(i);
    g[s[0]-'0'][s[s.size()-1]-'0']++;
  }
  ll ans=0;
  rep(i,1,10){
    rep(j,1,i+1){
      ans+=g[i][j]*g[j][i];
      if(i!=j)ans+=g[i][j]*g[j][i];
    }
  }
  cout<<ans<<endl;
}

