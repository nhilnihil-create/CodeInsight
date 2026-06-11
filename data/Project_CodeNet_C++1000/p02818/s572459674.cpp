#include <bits/stdc++.h>

#define rep(i, n) for (int i = 0; i < (n); i++)

using namespace std;

using ll = long long;

int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  ll a, b, k;
  cin >> a >> b >> k;
  cout << max(0LL, a - k) << ' ' << max(0LL, min(b, a + b - k));
  return 0;
}
