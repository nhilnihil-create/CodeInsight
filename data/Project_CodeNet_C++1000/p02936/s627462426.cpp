#include<bits/stdc++.h>
using namespace std;
using ll = long long;
#define rep(i,n) for(ll i=0;i<(ll)n;++i)
using P = pair<ll,ll>;

vector<vector<ll>> to(200005);
vector<ll> ans;

void dfs( ll p, ll q ){
  for(auto v : to.at(p) ){
    if( v == q ) continue;
    ans.at(v) += ans.at(p);
    dfs(v,p);
  }
}

int main(){
  ll n,q;cin >> n >> q;
  rep(i,n-1){
    ll a,b;cin >> a >> b;
    --a;--b;
    to.at(a).push_back(b);
    to.at(b).push_back(a);
  }

  ans.resize(n);
  rep(i,q){
    ll p,x;cin >> p >> x;
    --p;
    ans.at(p) += x;
  }

  dfs(0,0);

  rep(i,n){
    cout << ans.at(i);
    if( i != n-1 ) cout << " ";
    else cout << endl;
  }
  return 0;
}
