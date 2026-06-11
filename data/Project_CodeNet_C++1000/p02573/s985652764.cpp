#include<bits/stdc++.h>
#define rep(i,n) for (ll i=0; i<(n); i++)
using namespace std;
using ll = long long;
using ld = long double;
using vl = vector<ll>;

struct UnionFind {
    //自身が親であれば、その集合に属する頂点数に-1を掛けたもの
    //そうでなければ親のid
  vector<int> r;
 
  UnionFind(int N) {
    r = vector<int>(N, -1);
  }
 
  ll root (ll x) {
    if (r[x] < 0) return x;
    return r[x] = root(r[x]);
  }
 
  void unite (ll x, ll y) {
    x = root(x);
    y = root(y);
    if (x == y) return;
    if (r[x] > r[y]) swap(x, y);
    r[x] += r[y];
    r[y] = x;
  }
 
  ll size (ll x) {
    return -r[root(x)];
  }
};

int main() {
  ll n, m;
  cin >> n >> m;
  
  UnionFind uf(n);
  
  rep(i,m) {
    ll a, b;
    cin >> a >> b;
    a--; b--;
    uf.unite(a,b);
  }
  ll ans = 0;
  rep(i,n) ans = max(uf.size(i), ans);
  cout << ans << endl;
}