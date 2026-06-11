/**
 *    author:  morato
 *    created: 15.09.2020 09:02:33
**/
#include <bits/stdc++.h>

using namespace std;

int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  int64_t x;
  cin >> x;
  map<int64_t, int> mp;
  for (int64_t i = 2; i * i <= x; i++) {
    while (x % i == 0) {
      mp[i]++;
      x /= i;
    }
  }
  if (x > 1) mp[x]++;
  int ans = 0;
  for (auto it = mp.begin(); it != mp.end(); it++) {
    int cnt = 1;
    while (cnt <= it->second) {
      it->second -= cnt;
      cnt++;
      ans++;
    }
  }
  cout << ans << '\n';
  return 0;
}