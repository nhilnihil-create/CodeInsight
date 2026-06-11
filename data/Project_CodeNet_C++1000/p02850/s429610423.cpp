#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef vector<ll> vec;
typedef vector<vec> mat;
typedef pair<ll,ll> pll;
const ll mod=1e9+7;
//const ll mod=998244353;
const ll inf=1LL<<61;

const ll N=1e5+10;
vector<map<ll,ll>> G(N);
vec c(N);
ll n;

void dfs(ll f, ll pre) {
  ll ng=-1;
  if(pre!=-1) {
    ng=c[G[pre][f]];
  }
  ll cur=1;
  for(auto p:G[f]) {
    ll t=p.first;
    ll id=p.second;
    if(t==pre) continue;
    if(cur==ng) cur++;
    c[id]=cur++;
    dfs(t,f);
  }
}


int main() {
  cin >> n;
  for(ll i=0;i<n-1;i++) {
    ll a,b;
    cin >> a >> b;
    a--,b--;
    G[a][b]=i;
    G[b][a]=i;
  }
  ll ans=0;
  for(ll i=0;i<n;i++) {
    ans=max((ll)G[i].size(),ans);
  }
  cout << ans << endl;
  dfs(0,-1);
  for(ll i=0;i<n-1;i++) {
    cout << c[i] << endl;
  }
}