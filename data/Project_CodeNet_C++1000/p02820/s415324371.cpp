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
  int n, k;
  cin >> n >> k;
  map<char, int> m;
  cin >> m['s'] >> m['p'] >> m['r'];
  string s;
  cin >> s;
  int ans = 0;
  vector<int> d(s.size());
  for (int i = 0; i < n; i++) {
    if (i < k - 1 || !(s[i] == s[i - k] && d[i - k])) {
      ans += m[s[i]];
      d[i] = 1;
    }
  }
  cout << ans << '\n';
}

signed main() {
  ios::sync_with_stdio(0); cin.tie(0);
  int T = 1;
  // cin >> T;
  while (T--) MAIN();
}
