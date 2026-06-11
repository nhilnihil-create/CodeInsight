#include <bits/stdc++.h>
using namespace std;
typedef long long int ll;
typedef long double ld;
#define rep(i,n) for (ll i = 0; i < (n); ++i)
const ll mod = 1000000007;
const ll INF = 9223372036854775807;
#define Sort(a) sort(a.begin(), a.end())
#define Reverse(a) reverse(a.begin(), a.end())
#define Pi acos(-1)

int main() {
  cin.tie(0);
  ios_base::sync_with_stdio(false);
  cout << setprecision(15) << fixed;
  ll n, m;
  cin >> n >> m;
  vector<ll> a(n,-1);
  if (m == 0 && n == 1) {
      cout << 0 << '\n';
      return 0;
  }
  rep(i,m) {
    ll s, c;
    cin >> s >> c;
    if (a[s-1] == -1 || a[s-1] == c) {
      a[s-1] = c;
    }
    else {
      cout << -1 << '\n';
      return 0;
    }
    if (a[0] == 0 && a.size() > 1) {
      cout << -1 << '\n';
      return 0;
    }
  }
  rep(i,n) {
    if (a[i] == -1 && i == 0) {
      cout << 1;
    }
    else if (a[i] == -1) {
      cout << 0;
    }
    else {
      cout << a[i];
    }
  }
    cout << '\n';
}