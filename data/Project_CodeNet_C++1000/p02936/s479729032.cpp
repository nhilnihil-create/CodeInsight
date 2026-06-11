#include <bits/stdc++.h>
using namespace std;

#define ll long long

using Graph = vector<vector<ll>>;
Graph G;

void DFS(ll v, ll p, vector<ll> &res) {
  if (p != 0) res[v] += res[p];
  for (auto e : G[v]) {
    if (e == p) continue;
    DFS(e, v, res);
  }
}


int main() {
  ll N, Q;
  cin >> N >> Q;
  
  
  G.assign(200010, vector<ll>());
  
  
  
  // 木を作る
  for (int i = 0; i < N-1; i++) {
    ll a, b;
    cin >> a >> b;
    
    G[a].push_back(b);
    G[b].push_back(a);
  }
  
  vector<ll> count(200010, 0);

  
  // DFS
  for (int i = 0; i < Q; i++) {
    int p, x;
    cin >> p >> x;
    count[p] += x;
  }
  
  DFS(1, 0, count);
  
  
  // output
  for (int i = 1; i <= N; i++) {
    cout << count[i] << " ";
  }
  cout << endl;
  
  
}