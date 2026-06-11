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

vi topologicalSort(vvi &G) {
  ll V=G.size();
  vi in(V);
  for(vi &v:G) for(ll to:v) in[to]++;
  queue<ll> q;
  REP(i,V) if(in[i]==0) q.push(i);
  vi ret;
  while(q.size()) {
    ll from=q.front();
    q.pop();
    ret.PB(from);
    for(ll to:G[from]) {
      in[to]--;
      if(in[to]==0) q.push(to);
    }
  }
  return ret;
}

int main() {
  ll V,E; cin>>V>>E;
  vvi G(V);
  REP(i,E) {
    ll s,t; cin>>s>>t;
    G[s].PB(t);
  }
  vi ans=topologicalSort(G);
  for(ll i:ans) cout<<i<<endl;
}