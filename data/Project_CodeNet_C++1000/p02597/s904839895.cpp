/*input
2
RR
*/

#include <bits/stdc++.h>
#define rep(i, n) for (int i = 0; i < (n); ++i)
using namespace std;
using ll = long long;
using P = pair<int, int>;

int main() {
  int n;
  cin >> n;
  string s;
  cin >> s;

  int l = 0, r = n-1;
  int ans = 0;
  while (l < r) {
    if (s[l] == 'W' && s[r] == 'R') {
      ans++;
      l++; r--;
      continue;
    }
    if (s[l] == 'R') l++;
    if (s[r] == 'W') r--;
  }
  cout << ans <<endl;
}