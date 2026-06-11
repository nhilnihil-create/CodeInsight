#include <cstdio>
#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;
int N,M,Q;
int rank[100001],par[100001];
int find(int x){
  if(par[x]==x)return x;
  else return par[x]=find(par[x]);
}
void unite(int x,int y){
  x=find(x);
  y=find(y);
  if(x==y)return ;

  if(rank[x]<rank[y]){
    par[x]=y;
  }
  else{
    par[y]=x;
    if(rank[x]==rank[y])rank[x]++;
  }
}

bool same(int x,int y){
  return find(x)==find(y);
}
int main(){
  cin >> N >> M;
  for(int i=0;i<N;i++){
    par[i]=i;
    rank[i]=0;
  }
  for(int i=0;i<M;i++){
    int u,v;
    cin >> u >> v;
    unite(u,v);
  }
  cin >> Q;
  for(int i=0;i<Q;i++){
    int s,d;
    cin >> s >> d;
    if(same(s,d))printf("yes\n");
    else printf("no\n");
  }
  return 0;
}