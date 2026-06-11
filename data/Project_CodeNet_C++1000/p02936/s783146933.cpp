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
  ll n,k;cin>>n>>k;
  vvll g(n);vll cnt(n,0);vb visited(n,false);
  rep(i,0,n-1){
    ll a,b;cin>>a>>b;
    a--;b--;
    g[a].push_back(b);
    g[b].push_back(a);
  }
  rep(i,0,k){
    ll a,b;cin>>a>>b;
    cnt[a-1]+=b;
  }
  queue<ll> q;
  q.push(0);
  visited[0]=true;
  while(!q.empty()){
    ll tmp=q.front();
    q.pop();
    visited[tmp]=true;
    for(auto u:g[tmp]){
      if(visited[u])continue;
      cnt[u]+=cnt[tmp];
      q.push(u);
    }
  }
  rep(i,0,n){
    cout<<cnt[i]<<" ";
  }
  cout<<endl;
}

