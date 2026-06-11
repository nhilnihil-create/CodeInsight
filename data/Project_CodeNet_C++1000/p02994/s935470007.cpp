#include <bits/stdc++.h>

#define rep(i, n) for (int i = 0; i < n; i++)

using namespace std;

using ll = long long;

int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  int n, l;
  cin >> n >> l;
  int ans = 0, Min = 1000;
  rep(i, n) {
    int v = l + i;
    if (abs(v) < abs(Min)) Min = v;
    ans += v;
  }
  cerr << Min << endl;
  ans -= Min;
  cout << ans << '\n';
  return 0;
}
