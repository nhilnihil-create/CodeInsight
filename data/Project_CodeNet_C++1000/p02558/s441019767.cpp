#include<bits/stdc++.h>
using namespace std;
using LL = long long;
using ULL = unsigned long long;
#define rep(i,n) for(int i=0; i<(n); i++)

struct DSU{
 int N;
 vector<int> V;
 void init(int n){
  N=n; V.resize(N);
  rep(i,N) V[i]=i;
 }
 int root(int a){
  if(a==V[a]) return a;
  return V[a] = root(V[a]);
 }
 void unite(int a,int b){
  V[root(a)] = root(b);
 }
};

int main(){
 int N,Q; scanf("%d%d",&N,&Q);
 DSU G; G.init(N);
 rep(q,Q){
  int c; scanf("%d",&c);
  if(c==0){
   int x,y; scanf("%d%d",&x,&y);
   G.unite(x,y);
  }
  if(c==1){
   int x,y; scanf("%d%d",&x,&y);
   printf((G.root(x)==G.root(y)) ? "1\n" : "0\n");
  }
 }
 return 0;
}