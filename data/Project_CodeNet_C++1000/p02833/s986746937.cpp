#include <bits/stdc++.h>
#define rep(i, n) for (int i = 0; i < (int)(n); i++)

using namespace std;
using ll = long long;

int main() {
  ll n;
  cin >> n;
  if (n % 2 == 0) {
    ll div = 5;
    ll ans = 0;
    while (div < n) {
      ans += n / (2 * div);
      div *= 5;
    }
    cout << ans << endl;
  } else {
    cout << 0 << endl;
  }
  return 0;
}
