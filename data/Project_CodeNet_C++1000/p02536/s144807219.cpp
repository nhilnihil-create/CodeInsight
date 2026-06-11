#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
using ll = long long;

struct UnionFind {
  vector<int> d;
  // 子は親のIDを，根は木のサイズ*-1を持つ
  UnionFind(int n = 0): d(n,-1){}
  // rootを探索する
  int find(int x){
    if(d[x] < 0) return x;
    return d[x] = find(d[x]);
  }
  // 集合を統合する
  bool unite(int x, int y){
    x = find(x); y = find(y);
    if (x == y) return false;
    if (d[x] > d[y]) swap(x,y);
    d[x] += d[y];
    d[y] = x;
    return true;
  }
  // 同じ集合に属しているか判定
  bool same(int x, int y) {return find(x) == find(y);}
  // 集合のサイズを返す
  int size(int x) {return -d[find(x)];}
};

int main(){
  int n, m;
  cin >> n >> m;
  UnionFind uf(n);
  rep(i,m){
    int a, b;
    cin >> a >> b;
    a--; b--;
    if(!uf.same(a,b)) uf.unite(a,b);
  }  

  vector<int> arr(n,0);
  rep(i,n) arr[uf.find(i)] |= 1;
  int ans = -1;
  rep(i,n) if(arr[i]) ans++;
  cout << ans << endl;

  return 0;
}
