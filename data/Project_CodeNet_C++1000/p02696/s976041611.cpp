#include <bits/stdc++.h>
#define rep(i, n) for (int i = 0; i < n; i++)
using namespace std;
using ll = long long;
using P = pair<int, int>;

int main() {
  ll A, B, N;
  cin >> A >> B >> N;
  ll x = min(B - 1, N);
  ll ans = (A * x) / B;
  // ll n = min(B, N);
  // ll ans = 0;
  // for (ll x = n - 2; x <= n; x++) {
  //   ll y = (A * x) / B - A * (x / B);
  //   ans = max(ans, y);
  // }
  cout << ans << endl;
}
