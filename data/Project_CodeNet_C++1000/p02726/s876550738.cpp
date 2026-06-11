#include <bits/stdc++.h>
#define ft first
#define sc second
#define pt(sth) cout << sth << "\n"
using namespace std;
typedef long long ll;
typedef pair<ll, ll> pll;
template<class T>bool chmax(T &a, const T &b) {if(a<b) {a=b; return 1;} return 0;}
template<class T>bool chmin(T &a, const T &b) {if(b<a) {a=b; return 1;} return 0;}
static const ll INF=1e18;
static const ll MAX=101010;
static const ll MOD=1e9+7;
//for(i=0; i<N; i++) cin >> a[i];


// D - Line++
class Edge {
public:
  ll t, w;
  Edge() {}
  Edge(ll t, ll w): t(t), w(w) {}
};

ll N, M;
vector<Edge> g[2222];
ll d[2222][2222];

void dijkstra(ll s) {
  ll i, u;
  ll clr[2222]={};
  priority_queue<pll> q;
  for(i=0; i<N; i++) d[s][i]=INF;
  d[s][s]=0;
  q.push({0, s});
    
  while(q.size()) {
    ll du=-q.top().ft;
    ll u=q.top().sc;
    q.pop();
    
    if(clr[u]) continue;
    clr[u]=1;
    
    for(i=0; i<g[u].size(); i++) {
      Edge e=g[u][i];
      
      chmin(d[s][e.t], du+e.w);
      q.push({-d[s][e.t], e.t});
    }
  }
}

int main(void) {
  ll i, j, k;
  
  ll X, Y;
  cin >> N >> X >> Y;
  X--; Y--;
  
  for(i=0; i<N-1; i++) {
    g[i].push_back(Edge(i+1, 1));
    g[i+1].push_back(Edge(i, 1));
  }
  
  g[X].push_back(Edge(Y, 1));
  g[Y].push_back(Edge(X, 1));
  
  for(i=0; i<N; i++) dijkstra(i);
  
  ll cnt[2222]={};
  for(i=0; i<N; i++) for(j=i+1; j<N; j++) cnt[d[i][j]]++;
  
  for(i=1; i<N; i++) pt(cnt[i]);
  
  
  
}


