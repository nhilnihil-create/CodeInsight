#include<queue>
#include<math.h>
#include<cmath>
#include<bitset>
#include<stdio.h>
#include<string>
#include<map>
#include<algorithm>
#include<vector>
#include<iostream>
#include<utility>
using namespace std;
typedef long long ll;
typedef pair<ll,ll> pll;
typedef pair<ll,pll> P;
struct edge{
  ll to;
  ll cost;
  edge(ll t,ll w) : to(t),cost(w){}
};
int main(){
  vector<vector<edge> > g(100010);
  const ll INF=1000000000000000;
  priority_queue<P,vector<P>,greater<P> > que;
  ll n,m,u,V,s,t,i,j;
  ll ds[100010][5],ns[100010][5];
  scanf("%lld %lld\n",&n,&m);
  for(i=0;i<m;i++){
    scanf("%lld %lld\n",&u,&V);
    u--,V--;
    g[u].push_back(edge(V,1));
  }
  scanf("%lld %lld\n",&s,&t);
  s--,t--;
  for(i=0;i<n;i++){
    for(j=0;j<3;j++){
      ds[i][j]=INF,ns[i][j]=0;
    }
  }
  ds[s][0]=0;ns[s][0]=1;
  que.push(make_pair(0,pll(s,0)));
  while(!que.empty()){
    if(ns[t][0]==1){
      break;
    }
    P p=que.top();
    ll v=p.second.first,w=p.second.second;
    que.pop();
    for(i=0;i<g[v].size();i++){
      edge us=g[v][i];
      if(ds[us.to][(w+us.cost)%3]>ds[v][w]+us.cost && ns[us.to][(w+us.cost)%3]==0){
        ds[us.to][(w+us.cost)%3]=ds[v][w]+us.cost;
        que.push(make_pair(ds[us.to][(w+us.cost)%3],pll(us.to,(w+us.cost)%3)));
      }
    }
    ns[v][w]=1;
  }
  if(ds[t][0]==INF){
    printf("-1\n");
  }
  else{
    printf("%lld\n",ds[t][0]/3);
  }
  return 0;
}