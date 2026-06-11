#include <bits/stdc++.h>
#define pt(sth) cout << sth << "\n"
#define chmax(a, b) {if(a<b) a=b;}
#define chmin(a, b) {if(a>b) a=b;}
#define moC(a, s, b) (a)=((a)s(b)+MOD)%MOD
using namespace std;
typedef long long ll;
typedef pair<ll, ll> P;
static const ll INF=1e18;
static const ll MAX=101010;
static const ll MOD=1e9+7;

ll N, K;
vector<ll> g[MAX];

ll bfs() {
  ll res=K;
  queue<ll> q;
  ll i;
  ll used[MAX]={};
  used[0]=1;
  
  for(i=0; i<g[0].size(); i++) {
    moC(res, *, K-i-1);
    q.push(g[0][i]);
    used[g[0][i]]=1;
  }
  
  while(q.size()) {
    ll u=q.front(); q.pop();
    
    ll t=0;
    for(i=0; i<g[u].size(); i++) {
      ll v=g[u][i];
      if(used[v]) continue;
      
      moC(res, *, K-t-2);
      t++;
      q.push(v);
      used[v]=1;
    }
    
  }
  
  return res;
}

int main(void) {
  ll i, j, k;
  cin >> N >> K;
  
  for(i=0; i<N-1; i++) {
    ll a, b;
    cin >> a >> b;
    a--; b--;
    g[a].push_back(b);
    g[b].push_back(a);
  }
  
  pt(bfs());
  
}



