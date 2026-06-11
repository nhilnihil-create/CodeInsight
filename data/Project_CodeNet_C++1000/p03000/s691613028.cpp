#include <bits/stdc++.h>

#define rep(i, n) for (int i = 0; i < n; i++)

using namespace std;

using ll = long long;

int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  int n, x;
  cin >> n >> x;
  int sum = 0, ans = 1;
  rep(_, n) {
    int l;
    cin >> l;
    sum += l;
    if (sum > x) {
      cout << ans << '\n';
      return 0;
    }
    ans++;
  }
  cout << n + 1 << '\n';
  return 0;
}
