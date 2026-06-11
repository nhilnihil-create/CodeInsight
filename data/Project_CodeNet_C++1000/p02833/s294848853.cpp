#include <bits/stdc++.h>
#define rep(i, n) for (int i = 0; i < (n); ++i)
using namespace std;
using ll = int64_t;
using P = pair<int, int>;

int main() {
  ll n;
  cin >> n;

  ll ans = 0;
  if (n % 2 == 0) {
    for (ll i = 5; i <= n; i *= 5) {
      ans += n / i / 2;
    }
  }
  cout << ans << endl;
}
