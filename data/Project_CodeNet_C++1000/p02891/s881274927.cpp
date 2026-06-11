#include <bits/stdc++.h>
using namespace std;

// ----------- define --------------
#define int long long
#define vi vector<int>
#define vc vector<char>
#define ii pair<int,int>
#define fi first
#define sc second
#define stoi stoll
#define all(x) (x).begin(),(x).end()
#define get_bit(x, k) ((x >> k) & 1)
// ---------------------------------

void MAIN() {
  string s;
  cin >> s;
  int d; cin >> d;
  int n = s.size();
  int ans = 0, fi = 1, la = 1;
  for (int i = 0; i < n; i++) {
    int j = i;
    while (j < n - 1 && s[j + 1] == s[i]) j++;
    ans += (j - i + 1) / 2;
    if (i == 0) fi = j + 1;
    if (j == n - 1) la = j - i + 1;
    i = j;
  }
  if (fi == n) {
    cout << n * d / 2 << '\n';
    return;
  }
  if (d > 1 && s[0] == s[n - 1] && fi != n) {
    cout << ans + (d - 1) * (ans - fi / 2 - la / 2 + (fi + la) / 2) << '\n';
    return;
  }
  cout << ans * d << '\n';
}

signed main() {
  ios::sync_with_stdio(0); cin.tie(0);
  int T = 1;
  // cin >> T;
  while (T--) MAIN();
}
