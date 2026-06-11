#include <bits/stdc++.h>
#define rep(i, n) for (int i = 0; i < (int)(n); i++)

using namespace std;
using ll = long long;

int main() {
  ll n, a, b;
  cin >> n >> a >> b;
  ll ab = a + b;
  ll c = n / ab;
  ll d = n % ab;
  ll ans = c * a;
  if (d <= a) {
    ans += d;
  } else {
    ans += a;
  }
  cout << ans << endl;
  return 0;
}
