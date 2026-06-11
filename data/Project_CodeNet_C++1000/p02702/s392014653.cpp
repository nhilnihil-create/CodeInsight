#include <bits/stdc++.h>
using namespace std;

// ----------- define --------------
#define int long long
#define ii pair<int,int>
#define fi first
#define sc second
#define all(x) (x).begin(),(x).end()
// ---------------------------------

#define pow abcdef
int pow(int a, int b) {
  if (b == 0) return 1;
  int t = pow(a, b / 2);
  t = (t * t) % 2019;
  if (b % 2) return (a * t) % 2019;
  return t;
}

void MAIN() {
  string s;
  cin >> s;
  reverse(all(s));
  vector<int> a(s.size());
  int ans = 0;
  map<int, int> m; m[0] = 1;
  for (int i = 0; i < s.size(); i++) {
    a[i] = (s[i] - '0') * pow(10, i);
    if (i) a[i] += a[i - 1];
    a[i] %= 2019;
    ans += m[a[i]];
    m[a[i]]++;
  }
  cout << ans << '\n';
}

signed main() {
  ios::sync_with_stdio(0); cin.tie(0);
  int T = 1;
  // cin >> T;
  while (T--) MAIN();
}
