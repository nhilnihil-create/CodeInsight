#include <bits/stdc++.h>
using namespace std;

#define int long long

#define ii pair<int,int>
#define fi first
#define sc second

#define all(x) (x).begin(),(x).end()

signed main() {
#ifdef _DEBUG
  freopen("in" , "r", stdin );
  // freopen("out", "w", stdout);
#endif
  ios::sync_with_stdio(0); cin.tie(0);
  string s;
  cin >> s;
  int n = s.size();
  vector<int> a(n + 1);
  for (int i = 0; i < s.size(); i++) {
    if (s[i] == '<') a[i + 1] = a[i] + 1;
  }
  for (int i = s.size() - 1; i >= 0; i--) {
    if (s[i] == '>') a[i] = max(a[i], a[i + 1] + 1);
  }
  int ans = 0;
  for (auto &i : a) ans += i;
  cout << ans << '\n';
}
