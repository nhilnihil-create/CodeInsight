#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
#define INF 100000000
#define MAX_E 100000
#define MAX_V 10000
struct edge{int u,v,cost;};
edge es[MAX_E];
int V,E;
int par[MAX_V];
int rank[MAX_V];
void init_union(){
  for(int i=0;i<V;i++){
    par[i]=i;
    rank[i]=0;
  }
}
int find(int x){
  if(par[x]==x)return x;
  else {
    return par[x]=find(par[x]);
  }
}
void unite(int x,int y){
  x=find(x);
  y=find(y);
  if(x==y)return ;

  if(rank[x] < rank[y]) par[x]=y;
  else {
    par[y]=x;
    if(rank[x]==rank[y])x++;
  }
}
bool same(int x,int y){
  return find(x)==find(y);
}
bool comp(const edge& e1, const edge& e2){
  return e1.cost < e2.cost;
}

int kruskal(){
  int ans=0;
  sort(es,es+E,comp);
  init_union();

  for(int i=0;i<E;i++){
    edge e=es[i];
    if(!same(e.u,e.v)){
      unite(e.u,e.v);
      ans+=e.cost;
    }
  }
  return ans;
}
int main(){
  cin >> V >> E;
  for(int i=0;i<E;i++){
    int s,t,w;
    edge e;
    cin >> s >> t >> w;
    e.u=s; e.v=t; e.cost=w;
    es[i]=e;
  }
 
  cout << kruskal() << endl ;
  return 0;
}