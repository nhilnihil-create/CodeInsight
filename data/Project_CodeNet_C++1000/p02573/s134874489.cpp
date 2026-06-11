#include <bits/stdc++.h>
using namespace std;
typedef long long int ll;
#define FOR(i,l,r) for(i=l;i<r;i++)
#define REP(i,n) FOR(i,0,n)
#define ALL(x) x.begin(),x.end()
#define P pair<ll,ll>
#define F first
#define S second
struct UnionFind{
  vector<int> par,size;
  UnionFind(int N):par(N),size(N){
    for(int i=0;i<N;i++)par[i]=i,size[i]=1;
  }
  int root(int x){
    if(par[x]==x)return x;
    return par[x]=root(par[x]);
  }
  void unite(int x,int y){
    int rx=root(x),ry=root(y);
    if(rx==ry)return;par[rx]=ry;
    size[ry]+=size[rx];
  }
  bool same(int x,int y){
    int rx=root(x),ry=root(y);
    return rx==ry;
  }
  int s(int x){
    return size[x];
  }
};
signed main(){
  int N,M,i,ans=1;cin>>N>>M;
  UnionFind UF(N);
  REP(i,M){
    int A,B;cin>>A>>B;
    UF.unite(A-1,B-1);
  }
  REP(i,N)ans=max(ans,UF.s(i));
  cout<<ans<<endl;
  return 0;
}