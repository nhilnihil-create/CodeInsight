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
  vector<ll>v(n, 0);
  for (ll i = 0; i < n; ++i) {
    cin >> v[i];
  }
  cout << fixed << setprecision(16);
  sort(v.begin(), v.end());
  ld ans = v[0];
  for (ll i = 1; i < n; ++i) ans = (ans + v[i]) / 2.0;
  cout << ans;
}
