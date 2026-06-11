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
ll roundd(ll x,ll n){
  if(x>n){return x%n;}
  else if(x<0){return x%n+n;}
  else return x;
}

int main(){
  ll n;cin>>n;
  
  vvll g(n,vll(0));vll e(n-1);
  rep(i,0,n-1){
    ll a,b;cin>>a>>b;
    a--;b--;
    e[i]=b;
    g[a].push_back(b);
    g[b].push_back(a);
  }
  ll color=0;
  rep(i,0,n){
    color=max(color,SIZE(g[i]));
  }
  vll ans(n,-1);
  queue<ll> q;
  q.push(0);
  ans[0]=-1;
  while(!q.empty()){
    ll tmp=q.front();
    q.pop();
    ll cnt=1;
    rep(i,0,SIZE(g[tmp])){
      if(ans[g[tmp][i]]==-1&&g[tmp][i]!=0){
        ans[g[tmp][i]]=roundd(ans[tmp]+cnt,color);
        cnt++;
        q.push(g[tmp][i]);
      }
    }
  }
  cout<<color<<endl;
  rep(i,0,n-1){
    cout<<ans[e[i]]%color+1<<endl;
  }
  
}

