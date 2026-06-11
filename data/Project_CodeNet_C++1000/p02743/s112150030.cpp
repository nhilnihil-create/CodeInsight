#include <bits/stdc++.h>

using namespace std;

using ll = long long;

int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  ll a, b, c;
  cin >> a >> b >> c;
  if (a + b >= c) {
    cout << "No" << '\n';
    return 0;
  }
  ll left = 4 * a * b;
  ll right = (c - a - b) * (c - a - b);
  if (left < right) {
    cout << "Yes" << '\n';
  } else {
    cout << "No" << '\n';
  }
  return 0;
}
