#include <bits/stdc++.h>
using namespace std;
#define rep(i,n) for (int i = 0; i < n; ++i)
using ll = long long;
const ll MOD = 1000000007;//998244353;
bool cmp(pair<ll,ll> &p1, pair<ll,ll> &p2){
   return p1.second > p2.second;
}
// UnionFind
// coding: https://youtu.be/TdR816rqc3s?t=726
// comment: https://youtu.be/TdR816rqc3s?t=6822
struct UnionFind {
  vector<int> d;
  vector<int> min_;
  UnionFind(int n=0): d(n,-1) {
     for (int i = 0; i < n; i++){
        min_.push_back(i);
     }
  }
  int find(int x) {
    if (d[x] < 0) return x;
    return d[x] = find(d[x]);
  }
  bool unite(int x, int y) {
    x = find(x); y = find(y);
    if (x == y) return false;
    if (d[x] > d[y]) swap(x,y);
    if (min_[x] > min_[y])min_[x] = min_[y];
    d[x] += d[y];
    d[y] = x;
    return true;
  }
  bool same(int x, int y) { return find(x) == find(y);}
  int size(int x) { return -d[find(x)];}
  int ret_min(int x){return min_[find(x)];}
};
int main() {
   ios::sync_with_stdio(false);
   cin.tie(0);
   int n, m; cin >> n >> m;
   vector<pair<ll,ll>> p;
   rep(i,n){
      int a, b; cin >> a >> b;
      p.push_back(make_pair(m-a+1, b));
   }
   sort(p.begin(), p.end(), cmp);
   UnionFind uf(100001);
   ll ans = 0;
   for (auto &&i : p)
   {
      if (i.first <= 0 || uf.same(0,i.first))continue;
      uf.unite(uf.ret_min(i.first)-1, i.first);
      ans += i.second;
   }
   cout << ans << endl;  
}