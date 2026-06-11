#include <bits/stdc++.h>
using namespace std;
using ll = int64_t;

#define deb(x) cout << #x << "=" << x << endl
#define deb2(x, y) cout << #x << "=" << x << ", " << #y << "=" << y << endl

void solve() {
  ll n;
  cin >> n;
  vector<ll> arr(n);
  for (auto &it : arr) {
    cin >> it;
  }
  sort(arr.begin(), arr.end());
  ll ans = 0;
  for (int i = 0; i < n; i++) {
    for (int j = i + 1; j < n; j++) {
      if (arr[i] == arr[j])
        continue;
      for (int k = j + 1; k < n; k++) {
        if (arr[i] == arr[k] || arr[j] == arr[k])
          continue;
        if (arr[i] + arr[j] > arr[k])
          ans++;
      }
    }
  }
  cout << ans << '\n';
}

int main() {
  ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
  ll test = 1;
  // cin >> test;
  while (test--) {
    solve();
  }
  return 0;
}
