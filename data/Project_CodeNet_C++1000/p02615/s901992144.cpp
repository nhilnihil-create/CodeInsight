#include <bits/stdc++.h>

using namespace std;

#define ll long long

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(0);
  cout.tie(0);

  int n;
  cin >> n;
  vector<int> a(n);
  for (int &x : a) cin >> x;
  ll ans = 0;
  sort(a.begin(), a.end());
  for (int k = 1; k < n; k++) {
    ans += a[n - k / 2 - 1];
  }
  cout << ans << "\n";

  return 0;
}