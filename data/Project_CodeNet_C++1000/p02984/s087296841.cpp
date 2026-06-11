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
  vector<ll>d(n, 0), m(n, 0);
  for (ll i = 0; i < n; ++i) cin >> d[i];
  ll t = 1, x = 0;
  for (ll i = 0; i < n; ++i) {
    if (t) x += d[i];
    else x -= d[i];
    t ^= 1;
  }
  m[0] = x;
  for (ll i = 1; i < n; ++i) m[i] = 2 * d[i - 1] - m[i - 1];
  for (auto i : m) cout << i << " ";
}
