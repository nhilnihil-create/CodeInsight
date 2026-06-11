#include <bits/stdc++.h>

using namespace std;

using ll = long long;

int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  ll x;
  cin >> x;
  for (ll a = -1000; a <= 1000; a++) {
    for (ll b = -1000; b <= 1000; b++) {
      ll left = a * a * a * a * a - b * b * b * b * b;
      if (left == x) {
        cout << a << ' ' << b << '\n';
        return 0;
      }
    }
  }
  return 0;
}
