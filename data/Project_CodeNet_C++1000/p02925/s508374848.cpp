#include <bits/stdc++.h>
using namespace std;
using ll = long long;

const ll NMAX = 1000;
const ll VMAX = NMAX * NMAX;

ll id[NMAX][NMAX];
vector<vector<ll>> g(VMAX);
vector<ll> length(VMAX, 0);
vector<bool> visited(VMAX, false);
vector<bool> calculated(VMAX, false);

ll getid(ll i, ll j) {
  if (i > j) swap(i, j);
  return id[i][j];
}

ll dfs(ll i) {
  if (visited[i] && calculated[i]) return length[i];
  if (visited[i] && !calculated[i]) return -1;

  visited[i] = true;
  length[i] = 1;

  for (ll next : g[i]) {
    ll result = dfs(next);
    if (result == -1) return -1;
    length[i] = max(length[i], result + 1);
  }

  calculated[i] = true;
  return length[i];
}

int main() {
  ll n;
  cin >> n;
 
  vector<vector<ll>> a(n, vector<ll>(n - 1));
  for (ll i = 0; i < n; i++) {
    for (ll j = 0; j < n - 1; j++) {
      cin >> a[i][j];
      a[i][j]--;
    }
  }

  ll v = 0;
  for (ll i = 0; i < n; i++) {
    for (ll j = 0; j < n; j++) {
      if (i < j) {
        id[i][j] = v;
        v++;
      }
    }
  }
  
  for (ll i = 0; i < n; i++) {
    for (ll j = 0; j < n - 1; j++) {
      a[i][j] = getid(i, a[i][j]);
    }
  }

  for (ll i = 0; i < n; i++) {
    for (ll j = 0; j < n - 2; j++) {
      g[a[i][j]].push_back(a[i][j + 1]);
    }
  }

  ll ans = 0;
  for (ll i = 0; i < v; i++) {
    ll result = dfs(i);
    if (result == -1) {
      cout << -1 << endl;
      return 0;
    }
    ans = max(ans, result);
  }
  cout << ans << endl;
  return 0;
}
