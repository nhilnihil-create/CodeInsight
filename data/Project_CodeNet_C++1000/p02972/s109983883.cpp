//author: Harsh :)
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
#define maxN 100007
using namespace std;
int main() {
  fastio;
  ll n = 0;
  cin >> n;
  vector<ll>v(n + 1, 0), par(n + 1, 0);
  vector<ll>good;
  for (ll i = 1; i <= n; ++i) cin >> v[i];
  for (ll i = n; i >= 1; --i) {
    ll x = 0;
    for (ll j = 2 * i; j <= n; j += i) {
      x ^= par[j];
    }
    par[i] = x ^ v[i];
    if (par[i] & 1)
      good.pb(i);
  }
  cout << good.size() << "\n";
  for (auto i : good) cout << i << " ";
}
