#include<bits/stdc++.h>
using namespace std;
using ll = long long;
using P = pair<ll,ll>;
#define rep(i,n) for(ll i=0;i<(ll)n;++i)

struct UnionFind{
  vector<ll> d;
  UnionFind( ll n=0 ) : d(n,-1) {}
  ll find( ll x ){
    if( d.at(x) < 0 ) return x;
    return d.at(x) = find( d.at(x) );
  }
  bool unite( ll x, ll y ){
    x = find(x);y = find(y);
    if( x == y ) return false;
    if( -d.at(x) < -d.at(y) ) swap(x,y);
    d.at(x) += d.at(y);
    d.at(y) = x;
    return true;
  }
  bool same( ll x, ll y ){ return find(x) == find(y); }
  ll size( ll x ){ return -d.at( find(x) ); }
};
typedef struct UnionFind UnionFInd;

int main(){
  ll n,m;cin >> n >> m;
  UnionFind uf(n);
  rep(i,m){
    ll a,b;cin >> a >> b;
    --a;
    --b;
    uf.unite(a,b);
  }
  set<ll> s;
  rep(i,n) s.insert(uf.find(i));
  cout << s.size()-1 << endl;
  return 0;
} 