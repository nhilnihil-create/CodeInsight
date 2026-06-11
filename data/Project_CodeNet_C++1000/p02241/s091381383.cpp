#include <iostream>
#include <algorithm>

using namespace std;

#define MAX_V 100
#define MAX_E 10000

int par[MAX_V],rank[MAX_V];
int V,E;

struct edge{ int u,v,cost; };
edge es[MAX_E];

bool comp(const edge &e1, const edge &e2){
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
  }else{
    return par[x] = find(par[x]);
  }
}

void unite(int x,int y){
  x = find(x);
  y = find(y);

  if(x == y){
    return;
  }

  if(rank[x] < rank[y]){
    par[x] = y;
  }else{
    par[y] = x;
    if(rank[x] == rank[y]){
      rank[x]++;
    } 
  }
}

bool same(int x,int y){
  return find(x) == find(y);
}

int kruskal(){
  sort(es, es + E, comp);

  init(V);
  int res = 0;

  for(int i = 0 ; i < E ; i++){
    edge e = es[i];

    if(!same(e.u,e.v)){
      unite(e.u,e.v);
      res += e.cost;
    }
  }
  return res;
}

int main(){
  int c;

  cin >> V;
  for(int i = 0 ; i < V ; i++){
    for(int j = 0 ; j < V ; j++){
      cin >> c;

      if(c == -1){
	continue;
      }

      edge e = {i,j,c};
      es[E++] = e;
    }
  }

  cout << kruskal() << endl; 

  return 0;
}