#include <bits/stdc++.h>

#define rep(i, n) for (int i = 0; i < (n); i++)

using namespace std;

using ll = long long;

int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  ll a, b, n;
  cin >> a >> b >> n;
  ll x = min(n, b - 1);
  cout << a * x / b - a * (x / b) << '\n';
  return 0;
}
