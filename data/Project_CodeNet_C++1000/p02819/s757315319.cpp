#include <bits/stdc++.h>

#define rep(i, n) for (int i = 0; i < (n); i++)

using namespace std;

using ll = long long;

int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  int x;
  cin >> x;
  if (x == 2) {
    cout << 2;
    return 0;
  }
  if (x % 2 == 0) x++;
  while (true) {
    bool ok = true;
    for (int i = 3; i * i <= x; i += 2) {
      if (x % i == 0) {
        ok = false;
        break;
      }
    }
    if (ok) break;
    x += 2;
  }
  cout << x;
  return 0;
}
