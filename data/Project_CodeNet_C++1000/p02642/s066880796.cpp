#include <bits/stdc++.h>

using namespace std;

using ll = long long;

int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  int n;
  cin >> n;
  // int mx = (int)1e6 + 1;
  vector<int> a(n);
  for (int i = 0; i < n; i++) {
    cin >> a[i];
  }
  int mx = *max_element(a.begin(), a.end());
  vector<int> cnt(mx + 1);
  for (int i = 0; i < n; i++) {
    cnt[a[i]]++;
  }
  vector<bool> ok(mx + 1, 1);
  for (int i = 0; i < n; i++) {
    if (cnt[a[i]] != 0) {
      for (int j = a[i] + a[i]; j <= mx; j += a[i]) {
        ok[j] = 0;
      }
    }
  }
  int ans = 0;
  for (int i = 0; i < n; i++) {
    if (cnt[a[i]] == 1 && ok[a[i]]) {
      ans++;
    }
  }
  cout << ans << '\n';
  return 0;
}
