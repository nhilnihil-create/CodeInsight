#include <bits/stdc++.h>
using namespace std;

struct UnionFind{
  vector<int> r;

  UnionFind(int N){
    r=vector<int>(N,-1);
  }

  int root(int x){
    if(r[x]<0) return x;
    return r[x]=root(r[x]);
  }

  bool unite(int x,int y){
    x=root(x);
    y=root(y);
    if(x>y) swap(x,y);
    if(x==y) return false;
    r[x]+=r[y];
    r[y]=x;
    return true;
  }

  int size(int x){
    return -r[root(x)];
  }
};

int main(){
  int n,m; cin>>n>>m;
  UnionFind UF(n);
  for(int i=0;i<m;i++){
    int a,b; cin>>a>>b;
    UF.unite(--a,--b);
  }
  int ans=0;
  for(int i=0;i<n;i++){
    ans=max(ans,UF.size(i));
  }
  cout<<ans;
}
