#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);

  ll A; cin >> A;
  ll B; cin >> B;
  ll C; cin >> C;
  if (C - A - B <= 0) {
    cout << "No" << '\n';
  } else if (4 * A * B < (C - A - B) * (C - A - B)) {
    cout << "Yes" << '\n';
  } else {
    cout << "No" << '\n';
  }

  return 0;
}