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
#define getbit(x, k) ((x >> k) & 1)
#define all(x) (x).begin(),(x).end()
// ---------------------------------

void MAIN() {
  int n, m;
  cin >> n >> m;
  vector<ii> a(n);
  for (auto &i : a) {
    cin >> i.sc >> i.fi;
    i.sc = -i.sc;
  }
  sort(all(a), greater<ii>());
  set<int> s;
  for (int i = 0; i < m; i++) {
    s.insert(-i);
  }
  int ans = 0;
  for (auto &i : a) {
    auto it = s.lower_bound(- m - i.sc);
    if (it != s.end()) {
      s.erase(it);
      ans += i.fi;
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
