#include <bits/stdc++.h>

using namespace std;

int main(void) {
  ios_base::sync_with_stdio(false);
  cin.tie(0);
  int64_t n;
  cin >> n;
  map<int64_t, int> fact;
  for (int64_t i = 2; i*i <= n; i++) {
    while (n%i == 0) {
      ++fact[i];
      n /= i;
    }
  }
  if (n != 1) ++fact[n];
  int ans = 0;
  for (auto& f : fact) {
    int l = 1, r = f.second;
    while (l < r) {
      int mid = (l + r + 1) >> 1;
      if ((mid*(mid+1))/2 <= f.second) l = mid;
      else r = mid-1;
    }
    // cerr << f.first << " " << l << '\n';
    ans += l;
  }
  cout << ans << '\n';
  return 0;
}