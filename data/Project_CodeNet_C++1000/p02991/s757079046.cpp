#include <bits/stdc++.h>
using namespace std;
typedef pair<int,int> P;
typedef long long ll;
typedef long double ld;
const int inf=1e9+7;
const ll longinf=1LL<<60;
#define REP(i,m,n) for(int i=(int)(m) ; i < (int) (n) ; ++i )
#define rep(i,n) REP(i,0,n)
#define F first
#define S second

const int mx=100010;
const ll mod=1e9+7;

typedef vector<vector<pair<ll,int>>> wgraph;
typedef pair<ll,int> pli;

vector<ll> bfs(wgraph v,int x){
  priority_queue<pli,vector<pli>,greater<pli>> q;
  vector<ll> dist(v.size(),longinf);
  dist[x]=0;
  q.push({0LL,x});

  while(q.size()){
    pli p=q.top(); q.pop();
    ll d=p.F, now=p.S;
    if(dist[now]<d){ continue; }
    for(auto to:v[now]){
      if(dist[to.S]>d+to.F){
        dist[to.S] = d+to.F;
        q.push({dist[to.S], to.S});
      }
    }
  }
  return dist;
}

int main(){
  int n,m;
  cin >> n >> m;
  wgraph v(mx*3);
  rep(i,m){
    int x,y,z=1;
    cin >> x >> y; x--; y--;
    v[x].emplace_back(z,y+mx);
    v[x+mx].emplace_back(z,y+mx+mx);
    v[x+mx+mx].emplace_back(z,y);
  }
  int s,t;
  cin >> s >> t; s--; t--;
  vector<ll> dist=bfs(v,s);
  ll ans = dist[t];
  if(ans==longinf){
    ans = -1;
  } else {
    ans/=3;
  }
  cout << ans << endl;
  return 0;
}