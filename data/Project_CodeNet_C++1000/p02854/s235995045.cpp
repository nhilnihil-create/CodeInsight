#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main() {
  ll n;
  cin >> n;
  ll s[n];  // a_0 ~ a_i の累積和
  ll sum = 0;
  for (int i = 0; i < n; i++) {
    ll a;
    cin >> a;
    if (i == 0) {
      s[0] = a;
    } else {
      s[i] = s[i - 1] + a;
    }
    sum += a;
  }

  ll ans = 1e18;
  for (int i = 0; i < n; i++) {
    ans = min(ans, abs(sum - 2 * s[i]));
  }

  cout << ans << endl;
}