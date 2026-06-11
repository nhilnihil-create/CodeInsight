#include <bits/stdc++.h>
#include <iostream>
#include <algorithm>
using namespace std;
#define _GLIBCXX_DEBUG
typedef long long ll;
const ll mod=1000000007;
ll pow(ll x,ll y){
  ll res=1;
  for(ll i=0;i<y;i++){
    res*=x;
  }
  return res;
}

ll powmod(ll x,ll y){
  ll res=1;
  for(ll i=0;i<y;i++){
    res=res*x%mod;
  }
  return res;
}
struct UnionFind {
  vector<int> d;
  UnionFind(int n=0): d(n,-1) {}
  int find(int x) {
    if (d[x] < 0) return x;
    return d[x] = find(d[x]);
  }
  bool unite(int x, int y) {
    x = find(x); y = find(y);
    if (x == y) return false;
    if (d[x] > d[y]) swap(x,y);
    d[x] += d[y];
    d[y] = x;
    return true;
  }
  bool same(int x, int y) { return find(x) == find(y);}
  int size(int x) { return -d[find(x)];}
};

main(){
  int n,m;cin >> n >> m;
  UnionFind uf(n);
  for(int i=0;i<m;i++){
    int a,b;cin >> a >> b;
    a--;b--;
    uf.unite(a,b);
  }
  int ans=0;
  for(int i=0;i<n;i++){
    ans=max(ans,uf.size(i));
  }
  cout << ans << endl;
  return 0;

}