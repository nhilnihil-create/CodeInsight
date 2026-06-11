#include <bits/stdc++.h>

using namespace std;


int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(0);
  int n;
  cin >> n;
  map<int, int> mp;
  long long ans = 0;
  for (int i = 0; i < n; i++) {
    int x;
    cin >> x;
    ans += mp[i - x];
    mp[i + x]++;
  }
  cout << ans << '\n';
  return 0;
}