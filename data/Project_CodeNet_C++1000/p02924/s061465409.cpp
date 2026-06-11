#include <bits/stdc++.h>
using namespace std;
using ll = int64_t;

int main() {
  ll n;
  cin >> n;

  ll ans(0);
  for (ll i = 1; i < n; i++) {
    ans += i;
  }
  cout << ans << endl;
}
