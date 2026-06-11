
#include <bits/stdc++.h>
#define rep(i,n) for (ll i = 0; i < (n); ++i)
using namespace std;
using ll = long long;
using P = pair<ll,ll>;
const ll INF=1e18;
struct UnionFind {
  vector<int> d;
  UnionFind(int n): d(n,-1) {}//-1で初期化
  int root(int x) {
    if (d[x] < 0) return x;//rootを負にする（構成node数x(-1))
    //root以外は親の番号
    return d[x] = root(d[x]);
    //return(root(d[x]))とするとメモできないが上の書き方だとメモができる
  }
  bool unite(int x, int y) {
    x = root(x); y = root(y);
    if (x == y) return false;
    if (d[x] > d[y]) swap(x,y);
    //swapすることで小さい方を大きい方につけられ計算量減らせる
    d[x] += d[y];
    d[y] = x;
    return true;
  }
  bool same(int x, int y) { return root(x) == root(y);}
  //同じグループ化
  int size(int x) { return -d[root(x)];}
  //グループのnode数
    int group_num(int n){
        set<int> s;
        for(int i = 0; i < n; ++i){
            s.insert(root(i));
        }
        return int(s.size());}
};


int main() {
  int n,q;
  cin>>n>>q;
  UnionFind uf(n);

  rep(i,q){
    int t1,u1,v1;

    cin>>t1>>u1>>v1;
  
    if(t1==0){
      uf.unite(u1,v1);
    }
    if(t1==1){
      if (uf.same(u1,v1)==1) cout<<1<<endl;
      else cout<<0<<endl;
    }
  }
}
