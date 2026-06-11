#include <bits/stdc++.h>

using namespace std;

using ll = long long;

int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  ll h, w;
  cin >> h >> w;
  if (h == 1 || w == 1) {
    cout << 1 << '\n';
    return 0;
  }
  cout << (h * w + 1) / 2 << '\n';
  return 0;
}
