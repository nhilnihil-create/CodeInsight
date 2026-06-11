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
const ll MOD = 1000000007;
string s;
bool can(ll x,ll y){
  rep(i,x,y){ 
    if(s[i]=='#'&&s[i+1]=='#'){
      return false;
    }
  }
  return true;
}

int main(){
  ll n,a,b,c,d;cin>>n>>a>>b>>c>>d;
  cin>>s;
  s="#"+s+"#";
  if(!can(a,c)||!can(b,d)){
    cout<<"No"<<endl;return 0;
  }
  if(d<c){
    bool ok=false;
    rep(i,b,d+1){
      if(s[i-1]=='.'&&s[i]=='.'&&s[i+1]=='.'){
        ok=true;
      }
    }
    if(!ok){
      cout<<"No"<<endl;return 0;
    }
  }
  cout<<"Yes"<<endl;
}


