#include <bits/stdc++.h>

#define rep(i, n) for (int i = 0; i < (n); i++)

using namespace std;

using ll = long long;

int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  int x;
  cin >> x;
  for (int i = 1; i <= 1000; i++) {
    if (100 * i <= x && x <= 105 * i) {
      cout << 1;
      return 0;
    }
  }
  cout << 0;
  return 0;
}
