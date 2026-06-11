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
  ll n,ans=1;cin>>n;
  vll cnt(n,0);
  rep(i,0,n){
    ll a;cin>>a;
    if(cnt[a]==0){
      if(a!=0)ans*=cnt[a-1];
      else{ans*=3;}
    }
    else{
      ans*=min(cnt[a-1]-cnt[a],(3-cnt[a]));
    }
    ans%=MOD;
    cnt[a]++;
  }
  cout<<ans<<endl;
}

