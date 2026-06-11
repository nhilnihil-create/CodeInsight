#include<bits/stdc++.h>

using namespace std;

typedef long long int ll;

const ll mod = 1e9 + 7;
const ll MAXN = 1e5 + 5;

vector < vector < ll > > adj(MAXN, vector < ll > ());
vector < vector < ll > > d(MAXN, vector < ll > (3, LLONG_MAX));
vector < bool > used(MAXN, false);

int main(){
  ios_base::sync_with_stdio(false);
  cin.tie(0);cout.tie(0);

  ll n, m;
  cin >> n >> m;
  for(int i = 0; i < m; i++){
    ll u, v;
    cin >> u >> v;
    adj[u].push_back(v);
  }
  ll st, t;
  cin >> st >> t;

  d[st][0] = 0;
  set < pair < vector < ll >, ll > > s;
  s.insert({d[st], st});
  while(!s.empty()){
    ll u = s.begin() -> second;
    s.erase(s.begin());
    for(auto to : adj[u]){
      if(d[u][0] != LLONG_MAX && d[to][1] > d[u][0] + 1){
        s.erase({d[to], to});
        d[to][1] = d[u][0] + 1;
        s.insert({d[to], to});
      }
      if(d[u][1] != LLONG_MAX && d[to][2] > d[u][1] + 1){
        s.erase({d[to], to});
        d[to][2] = d[u][1] + 1;
        s.insert({d[to], to});
      }
      if(d[u][2] != LLONG_MAX && d[to][0] > d[u][2] + 1){
        s.erase({d[to], to});
        d[to][0] = d[u][2] + 1;
        s.insert({d[to], to});
      }
    }
  }

  if(d[t][0] == LLONG_MAX) cout << -1 << endl;
  else cout << d[t][0] / 3 << endl;
}
