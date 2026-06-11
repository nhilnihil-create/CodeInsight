#include <bits/stdc++.h>
#define rep(i, n) for (int i = 0; i < (int)(n); i++)

using namespace std;
using ll = long long;

const int INF = 1001001001;

int main() {
  int n, x, y;
  cin >> n >> x >> y;
  vector<int> ans(n, 0);
  x--;
  y--;
  rep(j, n) rep(i, j) {
    int a = abs(i - j);
    int b = abs(x - i) + abs(y - j) + 1;
    int c = abs(x - j) + abs(y - i) + 1;
    int m = min({a, b, c});
    ans[m]++;
  }
  for (int i = 1; i < n; i++) {
    cout << ans[i] << endl;
  }
  return 0;
}
