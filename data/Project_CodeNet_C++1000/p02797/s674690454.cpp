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
  ll k,a,b;cin>>k>>a>>b;
  vll ans(k);
  if(b==1e9){
    rep(i,0,k){
      if(i<a){ans[i]=b;}
      else ans[i]=b-1;
    }
  }
  else{
    rep(i,0,k){
      if(i<a)ans[i]=b;
      else ans[i]=b+1;
    }
  }
  rep(i,0,k){
    cout<<ans[i]<<" ";
  }
  cout<<endl;
}



