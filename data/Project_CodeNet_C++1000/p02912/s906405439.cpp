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
  priority_queue<ll> q;
  rep(i,0,n){
    ll a;cin>>a;
    q.push(a);
  }
  rep(i,0,m){
    ll tmp=q.top();
    q.pop();
    q.push(tmp/2);
  }
  ll ans=0;
  rep(i,0,n){
    ans+=q.top();
    q.pop();
  }
  cout<<ans<<endl;
}

