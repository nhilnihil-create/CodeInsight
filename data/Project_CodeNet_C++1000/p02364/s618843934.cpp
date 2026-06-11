#include <iostream>
#include <algorithm>
#define MAX_V 10000
#define MAX_E 100000

using namespace std;

struct edge{
  int from,to,cost;
  edge(int f = -1,int t = -1,int c = -1) : from(f) ,to(t) ,cost(c) {}
};

int V,E;
int par[MAX_V],rank[MAX_V];
edge es[MAX_E];

bool cmp(const edge &e1,const edge &e2){
  return e1.cost < e2.cost;
}

void init(int n){
  for(int i = 0 ; i < n ; i++){
    par[i] = i;
    rank[i] = 0;
  }
}

int find(int x){
  if(par[x] == x){
    return x;
  }
  return par[x] = find(par[x]);
}

void unite(int x,int y){
  x = find(x);
  y = find(y);

  if(x == y) return;
  if(rank[x] < rank[y]){
    par[x] = y;
  }else{
    par[y] = x;
    if(rank[x] == rank[y]) rank[x]++;
  }
}

bool same(int x,int y){
  return find(x) == find(y);
}

int kruskal(){
  sort(es, es+E, cmp);
  init(V);

  int res = 0;
  for(int i = 0 ; i < E ; i++){
    edge e = es[i];
    if(!same(e.from,e.to)){
      unite(e.from,e.to);
      res += e.cost;
    }
  }

  return res;
}

int main(){
  cin >> V >> E;
  for(int i = 0 ; i < E ; i++){
    cin >> es[i].from >> es[i].to >> es[i].cost;
  }
  cout << kruskal() << endl;

  return 0;
}