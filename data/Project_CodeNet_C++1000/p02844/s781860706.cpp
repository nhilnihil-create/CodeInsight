#include <bits/stdc++.h>
using namespace std;

// ----------- define --------------
#define int long long
#define vi vector<int>
#define ii pair<int,int>
#define fi first
#define sc second
#define stoi stoll
#define popcnt __builtin_popcount
#define getBit(x, k) ((x >> k) & 1)
#define all(x) (x).begin(),(x).end()
// ---------------------------------

void Main() {
  int n;
  string s;
  cin >> n >> s;
  int ans = 0;
  for (char i = '0'; i <= '9'; i++)
  for (char j = '0'; j <= '9'; j++)
  for (char k = '0'; k <= '9'; k++) {
    int cnt = 0;
    for (int h = 0; h < n; h++) {
      if (cnt == 2 && s[h] == k) cnt++;
      if (cnt == 1 && s[h] == j) cnt++;
      if (cnt == 0 && s[h] == i) cnt++;
    }
    if (cnt == 3) ans++;
  }
  cout << ans << '\n';
}

signed main() {
#ifdef _DEBUG
  // freopen("in" , "r", stdin );
  cerr << "- ---- -- ----- <3\n";
#endif
  cin.tie(0)->sync_with_stdio(0);
  int T = 1;
  // cin >> T;
  while (T--) Main();
}
