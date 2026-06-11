#include <bits/stdc++.h>
#define rep(i, n) for (ll i = 0; i < (int)(n); i++)
using namespace std;
using ll = long long;

const ll INF = 1000000007;
const ll MAX_N = 100010;
ll res;
ll N, K;
vector<vector<ll>> G(MAX_N, vector<ll>(0));
vector<bool> gone(MAX_N, false);

void dfs(ll x) {
  gone[x] = true;
  ll cnt = 0;
  for (auto g : G[x]) {
    if (!gone[g]) {
      cnt++;
    }
  }
  if (x == 0) {
    rep(i, cnt) {
      res *= (K-1-i);
      res %= INF;
    }
  }
  else {
    rep(i, cnt) {
      res *= (K-2-i);
      res %= INF;
    }
  }
  for (auto g : G[x]) {
    if (!gone[g]) {
      dfs(g);
    }
  }
}

int main() {
  cin >> N >> K;
  rep(i, N-1) {
    ll a, b;
    cin >> a >> b;
    --a; --b;
    G[a].push_back(b);
    G[b].push_back(a);
  }
  res = K;
  dfs(0);
  cout << res << endl;
}