#include <bits/stdc++.h>
using ll = long long;
using ld = long double;
#define F first
#define S second
const ll mod = 1e9 + 7;
const ll INF = 922337203685477;
#define pb push_back
#define deb(x) cout << '>' << #x << ':' << x << endl;
#define fastio ios_base::sync_with_stdio(false); cin.tie(0);
#define maxN 200007
using namespace std;
int main() {
  fastio;
  ll n = 0, m = 0, bombs = 0;
  cin >> n >> m >> bombs;
  vector<ll>row(n, 0);
  vector<ll>col(m, 0);
  set<pair<ll, ll>>s;
  for (ll i = 0; i < bombs; ++i) {
    ll r = 0, c = 0;
    cin >> r >> c;
    --r, --c;
    s.insert({r, c});
    ++row[r], ++col[c];
  }
  ll rmax = *max_element(row.begin(), row.end());
  ll cmax = *max_element(col.begin(), col.end());
  vector<ll>row_ind, col_ind;
  for (ll i = 0; i < n; ++i) {
    if (row[i] == rmax)
      row_ind.pb(i);
  }
  for (ll i = 0; i < m; ++i) {
    if (col[i] == cmax)
      col_ind.pb(i);
  }
  if (row_ind.size()*col_ind.size() > bombs) {
    cout << rmax + cmax;
    return 0;
  }
  ll destroyed = 0;
  for (auto i : row_ind) {
    for (auto j : col_ind) {
      if (s.count({i, j}))
        destroyed = max(destroyed, row[i] + col[j] - 1);
      else
        destroyed = max(destroyed, row[i] + col[j]);
    }
  }
  cout << destroyed;
}