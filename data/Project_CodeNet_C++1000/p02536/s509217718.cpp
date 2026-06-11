#include <bits/stdc++.h>
#define rep(i, n) for(int i= 0; i < (n); i++)
using ll= long long int;
using namespace std;
template<class T> inline bool chmax(T& a, T b) { if (a < b) { a = b; return 1; } return 0; }
template<class T> inline bool chmin(T& a, T b) { if (a > b) { a = b; return 1; } return 0; }
ll mod= 1e9 + 7;

struct UnionFind {
    vector<int> par; // par[i]:iの親の番号　(例) par[3] = 2 : 3の親が2

    UnionFind(int N) : par(N) { //最初は全てが根であるとして初期化
        for(int i = 0; i < N; i++) par[i] = i;
    }

    int root(int x) { // データxが属する木の根を再帰で得る：root(x) = {xの木の根}
        if (par[x] == x) return x;
        return par[x] = root(par[x]);
    }

    void unite(int x, int y) { // xとyの木を併合
        int rx = root(x); //xの根をrx
        int ry = root(y); //yの根をry
        if (rx == ry) return; //xとyの根が同じ(=同じ木にある)時はそのまま
        par[rx] = ry; //xとyの根が同じでない(=同じ木にない)時：xの根rxをyの根ryにつける
    }

    bool same(int x, int y) { // 2つのデータx, yが属する木が同じならtrueを返す
        int rx = root(x);
        int ry = root(y);
        return rx == ry;
    }

    int maxlong(int x){ //最大の木の長さ(親の数を数える)
      int ans=0;
      int a[x]={};
      rep(i,x){
      a[root(i)]++;
      }
      rep(i,x){chmax(ans,a[i]);}
      return ans;
    }

};

int main() {
  int n,m;
  cin >>n >>m;
  UnionFind tree(n);
  rep(i,m){
    int a,b;
    cin >> a >>b;
    a--,b--;
    tree.unite(a,b);
  }
  int ans=0;
  rep(i,n){
    if(!tree.same(0,i)){
      ans++;
      tree.unite(0,i);
    }
  }
  cout << ans << endl;
}