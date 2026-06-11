#include <bits/stdc++.h>
#define rep(i, a, n) for (int i = a; i < n; i++)
#define repr(i, a, n) for (int i = n - 1; i >= a; i--)
using namespace std;
using ll = long long;
using P = pair<int, int>;

int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);

  string s, t;
  cin >> s >> t;
  int ans = 0;
  rep(i, 0, 3) if (s[i] == t[i]) ans++;
  cout << ans << endl;
}
