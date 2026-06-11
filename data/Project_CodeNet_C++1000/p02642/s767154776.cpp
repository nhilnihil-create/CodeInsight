/**
 *    author:  morato
 *    created: 29.08.2020 17:24:30
**/
#include <bits/stdc++.h>

using namespace std;

map<int, bool> ok;
map<int, int> freq;

int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  int n;
  cin >> n;
  vector<int> v(n);
  for (int i = 0; i < n; i++) {
    cin >> v[i];
    freq[v[i]]++;
    ok[v[i]] = true;
  }
  sort(v.begin(), v.end());
  int ans = 0;
  for (int i = 0; i < n; i++) {
    for (int j = v[i] + v[i]; j <= v[n - 1]; j += v[i]) {
      ok[j] = false;
    }
    ok[v[i]] &= (freq[v[i]] == 1);
    ans += (int) ok[v[i]];
  }
  cout << ans << '\n';
  return 0;
}