#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)

int main() {
  int n, x, y;
  cin >> n >> x >> y;

  vector<int> dist(n + 1, 0);
  x--;
  y--;

  rep(l, n) {
    for (int r = l + 1; r < n; r++) {
      int d = r - l;
      if (l <= x && r >= y) d -= y - x - 1;
      int w = abs(x - l) + abs(y - r) + 1;
      // printf("%d %d %d\n", l, r, d);
      dist[min(d, w)]++;
    }
  }

  rep(i, n - 1) { cout << dist[i + 1] << endl; }

  return 0;
}
