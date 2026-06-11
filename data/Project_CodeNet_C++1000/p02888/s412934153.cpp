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


int main(){
  ll n;cin>>n;
  vll a(n);
  rep(i,0,n){
    cin>>a[i];
  }
  ll ans=0;
  sort(a.begin(),a.end());
  rep(i,0,n){
    rep(j,0,i){
      auto it=lower_bound(a.begin()+i+1,a.end(),a[i]+a[j]);
      ans+=it-a.begin()-i-1;
    }
  }
  cout<<ans<<endl;
}

