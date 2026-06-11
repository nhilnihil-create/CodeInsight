#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main() {
  ll N;
  cin >> N;
  if (N % 2 == 1) cout << 0 << endl;
  else {
    ll ans = 0;
    for (ll i = 10; i <= N; i *= 5) {
      ans += N/i;
    }
    cout << ans << endl;
  }
}
