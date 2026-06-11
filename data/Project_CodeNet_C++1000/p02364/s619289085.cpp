#include<cstdio>
#include<algorithm>
#include<iostream>
#include<string>

using namespace std;


struct edge {int u,v,cost;};
edge cookies[100000000];

int V,E;
int par[1000000],rank[10000000];

void init(int n){
  for(int i=0;i<n;i++){
    par[i]=i;
    rank[i]=0;
  }
}

int find(int x){
  if(par[x]==x){
    return x;
  } else {
    return par[x]=find(par[x]);
  }
}

void unite(int x,int y){
  x=find(x);
  y=find(y);
  if(x==y) return;

  if(rank[x]<rank[y]){
    par[x]=y;
  } else {
    par[y]=x;
    if(rank[x]==rank[y]) rank[x]++;
  }
}

bool same(int x,int y){
  return find(x)==find(y);
}

bool comp(const edge& e1,const edge& e2){
  return e1.cost<e2.cost;
}

int kruskal(){
  sort(cookies,cookies+E,comp);
  init(V);
  int res=0;

  for(int i=0;i<E;i++){
    edge e=cookies[i];
    if(!same(e.u,e.v)){
      unite(e.u,e.v);
      res+=e.cost;
    }
  }
  return res;

}


int main(){
  scanf("%d%d",&V,&E);
  for(int i=0;i<E;i++){
    scanf("%d%d%d",&cookies[i].u,&cookies[i].v,&cookies[i].cost);
  }


  printf("%d\n",kruskal());

  return 0;

}