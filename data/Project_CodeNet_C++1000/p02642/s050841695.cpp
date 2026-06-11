#include <bits/stdc++.h>

using namespace std;

using ll = long long;

int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  int n;
  cin >> n;
  int mx = (int)1e6 + 1;
  vector<int> a(n), cnt(mx);
  for (int i = 0; i < n; i++) {
    cin >> a[i];
    cnt[a[i]]++;
  }
  vector<bool> ok(mx, 1);
  for (int i = 1; i < mx; i++) {
    if (cnt[i] != 0) {
      for (int j = i + i; j < mx; j += i) {
        ok[j] = 0;
      }
    }
  }
  int ans = 0;
  for (int i = 1; i < mx; i++) {
    if (cnt[i] == 1 && ok[i]) {
      ans++;
    }
  }
  cout << ans << '\n';
  return 0;
}
