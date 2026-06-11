#include<iostream>
#include<algorithm>
#include<cstdio>
#include<cmath>
#include<math.h>
#include<string>
#include<string.h>
#include<stack>
#include<queue>
#include<vector>
#include<utility>
#include<set>
#include<map>
#include<stdlib.h>
#include<iomanip>

using namespace std;

#define ll long long
#define ld long double
#define EPS 0.0000000001
#define INF 1e9
#define rep(i,n) for(i=0;i<n;i++)
#define loop(i,a,n) for(i=a;i<n;i++)
#define all(in) in.begin(),in.end()
#define shosu(x) fixed<<setprecision(x)

typedef vector<int> vi;
typedef pair<int,int> pii;


struct edge{ int u, v, cost; };

bool comp(const edge& e1, const edge& e2){

  return e1.cost < e2.cost;

}

#define MAX_N 100000
#define MAX_E 100000

int par[MAX_N];

int rank[MAX_N];

void init(int n){

  for(int i = 0 ; i < n ; i++){

    par[i] = i;

    rank[i] = 0;

  }

}

int find(int x){

  if(par[x] == x) return x;

  else return par[x] = find(par[x]);

}

void unite(int x, int y){

  x = find(x);

  y = find(y);

  if(x == y) return;

  if(rank[x] == rank[y]) par[x] = y;

  else par[y] = x;

  if(rank[x] == rank[y]) rank[x]++;
 
}

bool same(int x, int y){

  return find(x) == find(y);

}

edge es[MAX_E];

int V, E;

int kruskal(){

  sort(es, es+E, comp);

  init(V);

  int res = 0;

  for(int i = 0 ; i < E ; i++){

    edge e = es[i];

    if(!same(e.u, e.v)){

      unite(e.u, e.v);

      res += e.cost;

    }

  }

  return res;

}

int main(){
  int n;
  cin>>n;
  V=n;
  int i,j,k;
  E=0;
  rep(i,n)rep(j,n){
    int t;
    cin>>t;
    if(t<0)continue;
    es[E].u=i;
    es[E].v=j;
    es[E].cost=t;
    E++;
  }
  cout<<kruskal()<<endl;
}