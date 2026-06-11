#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const ll INF = 1e9;
const ll mod = 1e9+7;
ll N, K;
vector<ll> G[100000];
ll rk[100000];


void getrank() {
  for (ll i = 0; i < 100000; i++) {
    rk[i] = INF;
  }
  rk[0] = 0;
  queue<ll> que;
  que.push(0);
  while (!que.empty()) {
    ll v = que.front();
    que.pop();
    for (ll i = 0; i < G[v].size(); i++) {
      ll to = G[v][i];
      if (rk[to] == INF) {
        rk[to] = rk[v]+1;
        que.push(to);
      } else {
        continue;
      }
    }
  }
}

ll solve() {
  ll res = K;
  queue<ll> que;
  que.push(0);
  while (!que.empty()) {
    ll v = que.front();
    que.pop();
    if (rk[v] == 0) {
      for (ll i = 0; i < G[v].size(); i++) {
        ll to = G[v][i];
        res = res * (K-1-i) % mod;
        que.push(to);
      }
    } else {
      for (ll i = 0; i < G[v].size(); i++) {
        ll to = G[v][i];
        if (rk[to] > rk[v]) {que.push(to);}
      }
      if (K-1 >= G[v].size()) {
        for (ll i = 0; i < G[v].size()-1; i++) {
          res = res * (K-2-i) % mod;
        }
      } else {
        res = 0;
      }
    }
  }
  return res;
}

int main() {
  cin >> N >> K;
  for (ll i = 0; i < N-1; i++) {
    ll a, b; cin >> a >> b; a--; b--;
    G[a].push_back(b); G[b].push_back(a);
  }
  
  getrank();
  cout << solve() << endl;
}