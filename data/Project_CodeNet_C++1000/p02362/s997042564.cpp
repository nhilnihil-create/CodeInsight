#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define REP(i,n) FOR(i,0,n)
#define FOR(i,a,b) for(ll i=a;i<b;i++)
#define PB push_back
typedef vector<ll> vi;
typedef vector<vector<ll>> vvi;
const ll INF = (1ll << 60);
typedef pair<ll,ll> pii;
struct Edge{ll s,t,d;};
typedef vector<vector<Edge>> Graph;


int main(){
  ll V,E,r; cin>>V>>E>>r;
  vector<Edge> edges(E);
  REP(i,E) cin>>edges[i].s>>edges[i].t>>edges[i].d;
  Graph graph(V);
  for(Edge edge:edges) graph[edge.s].PB(edge);
  vi dist(V,INF);
  dist[r]=0;
  for(int cnt=0;;cnt++){
    REP(i,V) for(Edge e:graph[i]){
      if(dist[e.s]==INF) continue;
      if(dist[e.t]>dist[e.s]+e.d){
        dist[e.t]=dist[e.s]+e.d;
        if(cnt>V){
          cout<<"NEGATIVE CYCLE"<<endl;
          return 0;
        }
      }
    }
    if(cnt>V) break;
  }
  for(ll d:dist) if(d==INF) cout<<"INF"<<endl; else cout<<d<<endl;
}