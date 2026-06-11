#include <bits/stdc++.h>
#define all(x) (x).begin(), (x).end()
using namespace std;
typedef long long ll;
const int MOD = 1e9 + 7;

int main() {
  int n;
  cin >> n;
  vector<ll> x(n + 1, 0);
  for (int i = 1; i <= n; i++) {
    ll a;
    cin >> a;
    x[i] = x[i - 1] + a;
  }
  ll ans = 1e18;
  for (int i = 0; i < n; i++) {
    ll l = x[i];
    ll r = x[n] - x[i];
    ans = min(ans, abs(l - r));
  }
  cout << ans << endl;
  return 0;
}
