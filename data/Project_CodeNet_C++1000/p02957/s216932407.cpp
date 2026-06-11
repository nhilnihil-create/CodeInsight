#include <bits/stdc++.h>
#define rep(i, n) for (int i = 0; i < (n); ++i)
using namespace std;
using ll = long long;
using P = pair<int, int>;

int main() {
  int a, b;
  cin >> a >> b;
  if (a > b) swap(a, b);
  int diff = b - a;
  int ans;
  if (diff % 2 == 0) {
    ans = a + diff / 2;
    cout << ans << '\n';
  } else {
    cout << "IMPOSSIBLE" << '\n';
  }
  return 0;
}