#include <bits/stdc++.h>

using namespace std;

int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  int n, k;
  cin >> n >> k;
  vector<int> h(n);
  for (int i = 0; i < n; i++) {
    cin >> h[i];
  }
  sort(h.begin(), h.end(), greater<int>());
  long long ans = 0;
  for (int i = k; i < n; i++) {
    ans += h[i];
  }
  cout << ans << '\n';
  return 0;
}