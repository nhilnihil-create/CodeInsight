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
  vector<ll>a(n + 1, 0), b(n, 0);
  for (ll i = 0; i < n + 1; ++i) {
    cin >> a[i];
  }
  for (ll i = 0; i < n; ++i) cin >> b[i];
  ll ans = 0;
  for (ll i = 0; i < n; ++i) {
    ans += min(a[i], b[i]);
    b[i] -= min(a[i], b[i]);
    ans += min(a[i + 1], b[i]);
    a[i + 1] -= min(b[i], a[i + 1]);
  }
  cout << ans;
}
