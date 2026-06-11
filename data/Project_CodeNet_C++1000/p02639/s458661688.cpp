/**
 *    author:  morato
 *    created: 29.08.2020 17:10:22
**/
#include <bits/stdc++.h>

using namespace std;

int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  vector<int> v(5);
  int ans = 0;
  for (int i = 0; i < 5; i++) {
    cin >> v[i];
    if (!v[i]) {
      ans = i + 1;
    }
  }
  cout << ans << '\n';
  return 0;
}