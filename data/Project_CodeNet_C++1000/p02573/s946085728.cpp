#include <bits/stdc++.h>
using namespace std;
#include <math.h>
#include <iomanip>
template<class T> inline bool chmax(T& a, T b) { if (a < b) { a = b; return 1; } return 0; }
template<class T> inline bool chmin(T& a, T b) { if (a > b) { a = b; return 1; } return 0; }
const int INF=1001001001;
const int mod=1e9+7;

struct Unionfind{
  vector<int>d;
  Unionfind(int n):d(n,-1){}
  int root(int x){
    if(d[x]<0){return x;}
    return d[x]=root(d[x]);
  }
  bool unite(int x,int y){
    x=root(x);y=root(y);
    if(x==y){return false;}
    if(d[x]>d[y]){swap(x,y);}
    d[x]+=d[y];
    d[y]=x;
    return true;
  }
  bool same(int x,int y){return root(x)==root(y);}
  int size(int x){return -d[root(x)];}
};
int main(){
  int N,M;
  cin>>N>>M;
  Unionfind uf(N);
  for(int i=0;i<M;i++){
    int a,b;
    cin>>a>>b;
    a--;b--;
    uf.unite(a,b);
  }
  int MAX=0;
  for(int i=0;i<N;i++){
    chmax(MAX,uf.size(i));
  }
  cout<<MAX<<endl;
  return 0;                       
}