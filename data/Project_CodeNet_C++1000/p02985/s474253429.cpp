#include <bits/stdc++.h>
using namespace std;
using ll = long long;

const ll mod = 1e9 + 7;
const ll nmax = 1e5 + 5;
vector<vector<ll>> g(nmax, vector<ll>());
ll k;

ll dfs(ll used = 0, ll now = 0, ll parent = -1) {
  ll ans = k - used;

  if (used < 2) {
    used++;
  } else {
    used = 2;
  }

  for (auto next : g[now]) {
    if (next == parent) continue;
    ans *= dfs(used, next, now);
    ans %= mod;
    used++;
  }

  return ans;
}

int main() {
  ll n;
  cin >> n >> k;

  ll a, b;
  for (ll i = 0; i < n - 1; i++) {
    cin >> a >> b;
    a--;
    b--;
    g[a].push_back(b);
    g[b].push_back(a);
  }

  cout << dfs() << endl;
}
