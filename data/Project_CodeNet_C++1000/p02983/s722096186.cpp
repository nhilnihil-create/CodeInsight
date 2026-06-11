#include <bits/stdc++.h>
using namespace std;
using ll = long long;
typedef pair<int, int> P;
ll Mod = 1000000007;
int main() {
  ll L,R;
  cin >> L >> R;
  if (R - L > 2500) {
    cout << 0 << endl;
  } else {
    ll ans = 2050;
    for (ll i = L; i < R; i++) {
      for (ll j = i + 1LL; j <= R; j++) {
        ans = min(ans,(i * j) % 2019);
      }
    }
    cout << ans << endl;
  }
  return 0;
}