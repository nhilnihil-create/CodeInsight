#include <iostream>
#include <string>
#include <vector>
#include <set>
#include <queue>
#include <stack>
#include <map>
#include <algorithm>
#include <math.h>
#include <cassert>
#define rep(i,n) for(int i = 0; i < n; ++i )
using namespace std;
using ll = long long;
using P = pair<int,int>;
struct UnionFind {
  vector<int> parent,s;
  UnionFind(int n): parent(n), s(n){
    rep(i,n) {
      parent[i] = i;
      s[i] = 1;
    }
  }
  int root(int x) { return parent[x]==x ? x : parent[x] = root(parent[x]); }
  bool same(int x, int y) { return root(x)==root(y); }
  int size(int x){ return s[root(x)]; }
  void unite(int x, int y) {
    x = root(x); y = root(y);
    if (x == y) return;
    if (s[x] < s[y]) {
      parent[x] = y;
      s[y] += s[x];
    } else {
      parent[y] = x;
      s[x] += s[y];
    }   
  }
};

const ll inf = 1e18L;
int main() {
  int n,k;
  cin >> n >> k;
  vector<int> p(n),c(n);
  rep(i,n) cin >> p[i], --p[i];
  rep(i,n) cin >> c[i];

  UnionFind u(n);
  rep(i,n) u.unite(i,p[i]);
  vector<ll> s(n);
  rep(i,n) s[u.root(i)] += c[i];
  rep(i,n) s[i] = s[u.root(i)];

  ll ans = -inf;
  rep(i,n){
    ll res = -inf, t = 0;
    int m = k/u.size(i);
    if(m>=2 && s[i]>0) t += s[i]*(m-1);
    int v=i;
    m = min(k,k%u.size(i)+u.size(i));
    rep(_,m){
      t += c[v=p[v]];
      res = max(res,t);
    }
    ans = max({ans,res,t});
  }
  cout << ans << endl;
}