#include <bits/stdc++.h>
using namespace std;

using Int = long long;
const char newl = '\n';

template<typename T1,typename T2> inline void chmin(T1 &a,T2 b){if(a>b) a=b;}
template<typename T1,typename T2> inline void chmax(T1 &a,T2 b){if(a<b) a=b;}
template<typename T> void drop(const T &x){cout<<x<<endl;exit(0);}
template<typename T=int>
vector<T> read(size_t n){
  vector<T> ts(n);
  for(size_t i=0;i<n;i++) cin>>ts[i];
  return ts;
}


struct UnionFind{
  int num;
  vector<int> rs,ps;
  UnionFind(){}
  UnionFind(int n):num(n),rs(n,1),ps(n,0){iota(ps.begin(),ps.end(),0);}
  int find(int x){
    return (x==ps[x]?x:ps[x]=find(ps[x]));
  }
  bool same(int x,int y){
    return find(x)==find(y);
  }
  void unite(int x,int y){
    x=find(x);y=find(y);
    if(x==y) return;
    if(rs[x]<rs[y]) swap(x,y);
    rs[x]+=rs[y];
    ps[y]=x;
    num--;
  }
  int size(int x){
    return rs[find(x)];
  }
  int count() const{
    return num;
  }
};

//INSERT ABOVE HERE
signed main(){
  cin.tie(0);
  ios::sync_with_stdio(0);

  int n,m;
  cin>>n>>m;
  UnionFind uf(n);
  for(int i=0;i<m;i++){
    int a,b;
    cin>>a>>b;
    a--;b--;
    uf.unite(a,b);
  }
  int ans=0;
  for(int i=0;i<n;i++) chmax(ans,uf.size(i));
  cout<<ans<<newl;
  return 0;
}
