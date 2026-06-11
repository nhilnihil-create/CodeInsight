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

int main(){
  ll n,ans=0;cin>>n;
  vll a(n),b(n);
  rep(i,0,n){
    ll x;cin>>x;
    a[i]=i-x;b[i]=i+x;
  }
  sort(b.begin(),b.end());
  rep(i,0,n){
    auto it=lower_bound(b.begin(),b.end(),a[i]);
    auto it2=upper_bound(b.begin(),b.end(),a[i]);
    ans+=it2-it;
  }
  cout<<ans<<endl;
}

