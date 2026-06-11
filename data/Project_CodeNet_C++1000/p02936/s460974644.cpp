#include<bits/stdc++.h>
#define rep(i,f,n) for(ll i=(f); (i) < (n); i++)
#define repe(i,f,n) for(ll i=(f); (i) <= (n); i++)
using namespace std;
using ll = long long;

ll INF = 1LL << 60;

int 
main() {

  int N, Q; cin >> N >> Q;
  vector<vector<ll>> tree(N + 1);
  rep(i, 0, N - 1){
    ll a, b; cin >> a >> b;
    tree[a].push_back(b);
    tree[b].push_back(a);
  }

  vector<ll> imos(N + 1, 0);
  rep(i, 0, Q){
    int p, q; cin >> p >> q;
    imos[p] += q;
  }

  queue<ll> q;
  vector<bool> seen(N + 1, false);
  seen[1] = true;
  q.push(1);
  while(! q.empty()){
    ll nodes = q.front();
    q.pop();
    for(auto node: tree[nodes]){
      if(seen[node])continue;
      imos[node] += imos[nodes];
      seen[node] = true;
      q.push(node);
    }
  }

  rep(i, 1, N + 1){
    cout << imos[i] << endl;
  }
}
