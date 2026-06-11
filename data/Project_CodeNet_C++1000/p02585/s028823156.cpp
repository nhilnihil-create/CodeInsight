#include <bits/stdc++.h>
 
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
const ll inf=1e9;
const int MAX = 510000;
const ll MOD = 998244353;

inline ll mod(ll a, ll m) {
    return (a % m + m) % m;
}

int main(){
  ll n,k;cin>>n>>k;
  vll p(n),c(n);
  rep(i,0,n){
    cin>>p[i];p[i]--;
  }
  rep(i,0,n)cin>>c[i];
  ll ans=-inf;
  rep(i,0,n){
    ll v=i;
    ll sum=0,cnt=0;
    while(true){
      cnt++;
      sum+=c[v];
      v=p[v];
      if(v==i)break;
    }
    ll path=0,d=0;
    while(true){
      d++;
      path+=c[v];
      if(d>k)break;
      ll num=(k-d)/cnt;
      ll score=path+max(0LL,sum)*num;
      ans=max(ans,score);
      v=p[v];
      if(v==i)break;
    }
    
  }cout<<ans<<endl;
}




