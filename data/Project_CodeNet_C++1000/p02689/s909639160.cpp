#include <iostream>
#include <vector>

using ll = long long;
using namespace std;
#define REP(i, x, n) for(int i = x; i < n; i++)
#define rep(i, n) REP(i, 0, n)

int main() {
  ll n,m; cin>>n>>m;
  vector<ll> h(n); rep(i,n)cin>>h[i];
  vector<vector<ll>> g(n);
  rep(i,m){
    ll a,b; cin>>a>>b;
    a--; b--;
    g[a].push_back(b);
    g[b].push_back(a);
  }
  ll cnt=0;
  rep(i,n){
    bool f=true;
    for(auto &x: g[i]){
      f&=h[i] > h[x];
    }
    if(f) cnt++;
  }
  cout<<cnt<<endl;
  return 0;
}