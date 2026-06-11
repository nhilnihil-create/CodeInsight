#include <bits/stdc++.h>

using ll = long long;
using namespace std;
const int INFint = 1e9+1;
const ll INFll = (ll)1e18+1;
ll MOD=1e9+7;

struct UnionFind{
  vector<int> par;
  vector<int> siz;

  UnionFind(int N){
    par.resize(N);siz.resize(N);
    for(int i=0;i<N;i++) par[i]=i;
    for(int i=0;i<N;i++) siz[i]=1;
  }

  int root(int x){
    if(par[x]==x) return x;
    else return par[x]=root(par[x]);
  }

  bool unite(int x,int y){
    int rx=root(x);
    int ry=root(y);
    if (rx == ry) return false;
    if(siz[rx] < siz[ry]) swap(rx,ry);
    siz[rx] += siz[ry];
    par[ry] = rx;
    return true;
  }

  bool sameroot(int x,int y){
    return root(x)==root(y);
  }

  int size(int x){
    return siz[root(x)];
  }
};

int main(){
  int n,m;
  cin>>n>>m;
  UnionFind uf(n);
  for(int i(0);i<m;i++){
    int a,b;
    cin>>a>>b;
    a--;b--;
    uf.unite(a,b);
  }
  set<int> s;
  for(int i(0);i<n;i++){
    s.insert(uf.root(i));
  }
  cout << s.size() -1 << endl;
  return 0;
}

