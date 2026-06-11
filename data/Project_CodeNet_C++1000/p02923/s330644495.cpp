#include <bits/stdc++.h>

using namespace std;
using ll = long long;

#define rep(i, n) for (int i = 0; i < (int)(n); ++i)

int main() {
  int n;
  cin >> n;
  int h[n];
  rep(i, n) cin >> h[i];

  int ans = 0;
  int l = 0, r = 1;
  while (r < n) {
    if (h[r] <= h[r - 1])
      ++r;
    else {
      l = r;
      ++r;
    }
    ans = max(ans, r - l - 1);
  }

  cout << ans << endl;
  return 0;
}
