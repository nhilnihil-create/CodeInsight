#include<bits/stdc++.h>

using namespace std;

typedef long long int ll;

const ll mod = 1e9 + 7;
const ll MAXN = 3e5 + 5;

vector < vector < ll > > adj(MAXN, vector < ll > ());
vector < ll > d(MAXN, LLONG_MAX);
vector < bool > used(MAXN, false);

int main(){
  ios_base::sync_with_stdio(false);
  cin.tie(0);cout.tie(0);

  ll n, m;
  cin >> n >> m;
  for(int i = 0; i < m; i++){
    ll u, v;
    cin >> u >> v;
    adj[u].push_back(v + n);
    adj[u + n].push_back(v + 2 * n);
    adj[u + 2 * n].push_back(v);
  }
  ll st, ed;
  cin >> st >> ed;
  d[st] = 0;
  queue < ll > q;
  q.push(st);
  used[st] = true;
  while(!q.empty()){
    ll u = q.front(); q.pop();
    for(auto to : adj[u]){
      if(!used[to]){
        d[to] = min(d[to], d[u] + 1);
        used[to] = true;
        q.push(to);
      }
    }
  }

  if(d[ed] == LLONG_MAX) cout << -1 << endl;
  else{
    cout << d[ed] / 3 << endl;
  }
}
