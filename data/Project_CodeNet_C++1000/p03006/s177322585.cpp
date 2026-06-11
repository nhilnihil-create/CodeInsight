#include <bits/stdc++.h>
using namespace std;
#define rep(i,n) for (int i = 0; i < (int)(n); ++i)
#define rep2(i, s, n) for (int i = (s); i < (int)(n); i++)
struct UnionFind {
  vector<int> par; 

  UnionFind(int N) : par(N) { 
    rep(i,N) par[i] = i;
  }
  int root(int x) { 
    if (par[x] == x) return x;
    return par[x] = root(par[x]);
  }
  void unite(int x, int y) {
    int rx = root(x); 
    int ry = root(y);
    if (rx == ry) return; 
    par[rx] = ry; 
  }
  bool same(int x, int y) {
    int rx = root(x);
    int ry = root(y);
    return rx == ry;
  }
};

int main() {
  int n;
  cin >> n;
  vector<int>x(n),y(n);
  rep(i,n){
    cin>>x.at(i)>>y.at(i);
  }
  int ans=n;
  rep(i,n){
    rep2(j,i+1,n){
      int p=x.at(j)-x.at(i);
      int q=y.at(j)-y.at(i);
      
      int co=0;
  UnionFind tree(n);
  
  rep(k,n){
    rep(l,n){
      if(x.at(k)-x.at(l)==p&&y.at(k)-y.at(l)==q){
        tree.unite(k,l);
      }     
    }
  }
  vector<bool>a(n);
  rep(i,n){
    if(!a.at(tree.root(i))){
      a.at(tree.root(i))=true;
      co++;
    }
  }
      ans=min(ans,co);
    }
  }
  cout<<ans<<endl;
}