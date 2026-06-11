#include <bits/stdc++.h>
using namespace std;
using ll = int64_t;

#define deb(x) cout << #x << "=" << x << endl
#define deb2(x, y) cout << #x << "=" << x << ", " << #y << "=" << y << endl

void solve() {
  ll n, m;
  cin >> n >> m;
  ll sm = 0;
  for (ll i = 0; i < m; i++) {
    ll temp;
    cin >> temp;
    sm += temp;
  }
  if (n < sm) {
    cout << -1 << '\n';
    return;
  }
  cout << (n - sm) << '\n';
}

int main() {
  ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
  ll test = 1;
  // cin >> test;
  while (test--) {
    solve();
  }
  return 0;
}
