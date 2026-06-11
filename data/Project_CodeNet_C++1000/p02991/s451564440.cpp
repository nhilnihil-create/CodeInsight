//#define _GLIBCXX_DEBUG
#include<bits/stdc++.h>
#define PI 3.14159265359
using namespace std;
#define rep(i, n) for (ll i = 0; i < (ll)(n); i++)
const long long INF= 1e+18+1;
typedef long long ll;
typedef vector<ll> vl;
typedef vector<vector<ll> >vvl;
typedef pair<ll,ll> P;
typedef tuple<ll,ll,ll> T;
const ll MOD=1000000007LL;
string abc="abcdefghijklmnopqrstuvwxyz";
string ABC="ABCDEFGHIJKLMNOPQRSTUVWXYZ";
vl dx={-1,-1,-1,0,0,1,1,1};
vl dy={1,-1,0,1,-1,1,0,-1};

struct edge {
    ll to;
    ll cost;
};

ll V;
const ll MAX_V=500000;
vector<edge> G[MAX_V];
ll d[MAX_V];

void dijkstra(ll s) {
    priority_queue<P, vector<P>, greater<P> > que;
    fill(d, d+V, INF);
    d[s] = 0;
    que.push(P(0, s));

    while (!que.empty()) {
        P p = que.top();
        que.pop();
        ll v = p.second;
        if (d[v] < p.first) continue;

        for (ll i=0; i<G[v].size(); ++i) {
            edge e = G[v][i];
            if (d[e.to] > d[v] + e.cost) {
                d[e.to] = d[v] + e.cost;
                que.push(P(d[e.to], e.to));
            }
        }
    }
}

int main(){
  ll n;cin>>n;ll m;cin>>m;
  V=n*3;
  rep(i,m){
    ll u,v;cin>>u>>v;u--;v--;
    G[u].push_back(edge{v+n,1});
    G[u+n].push_back(edge{v+2*n,1});
    G[u+2*n].push_back(edge{v,1});
  }
  ll s,t;cin>>s>>t;
  s--;t--;
  dijkstra(s);
  if(d[t]>=INF)cout<<-1<<endl;
  else cout<<d[t]/3<<endl;
}