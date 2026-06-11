#include <bits/stdc++.h>
using namespace std;
typedef long long int ll;
typedef long double ld;
const ll mod = 1000000007;
const ll INF = 9223372036854775807;
#define Sort(a) sort(a.begin(), a.end())
#define Bsort(a) sort(a.begin(), a.end(), greater<ll>())
#define Pi acos(-1)

int main() {
  cin.tie(0);
  ios_base::sync_with_stdio(false);
  ll n, k;
  cin >> n >> k;
  ll r, s, p;
  cin >> r >> s >> p;
  string t;
  cin >> t;
  ll ans = 0;
  for (ll i = 0; i < k; i++) {
    if (t[i] == 'r') ans += p;
    else if (t[i] == 's') ans += r;
    else ans += s;
  }
  for(ll i = k; i < t.size(); i++) {
    if (t[i] == 'r') {
      if (t[i-k] == 'r') {
        t[i] = '0';
      }
      else {
        ans += p;
      }
    }
    else if (t[i] == 's') {
      if (t[i-k] == 's') {
        t[i] = '0';
      }
      else {
        ans += r;
      }
    }
    else {
      if (t[i-k] == 'p') {
        t[i] = '0';
      }
      else {
        ans += s;
      }
    }
  }
  cout << ans << '\n';
}