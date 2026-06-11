#include <bits/stdc++.h>
#define rep(i, n) for (int i = 0; i < (int)(n); i++)

using namespace std;
using ll = long long;

ll gcd(ll a, ll b) {
  if (a % b == 0) {
    return b;
  } else {
    return gcd(b, a % b);
  }
}

int main() {
  ll a, b;
  cin >> a >> b;
  ll g = gcd(a, b);
  int ans = 1;
  for (ll i = 2; i * i <= g; i++) {
    if (g % i) {
      continue;
    }
    ans++;
    while (g % i == 0) {
      g /= i;
    }
  }
  if (g != 1) {
    ans++;
  }
  cout << ans << endl;
  return 0;
}
