// J'aime
// Chemise Blanche

#include <bits/stdc++.h>
using namespace std;

#define int long long

#define ii pair<int,int>
#define fi first
#define sc second

#define all(x) (x).begin(),(x).end()
#define dbg(x) cerr << __LINE__ << " > " << #x << " = " << (x) << endl

void MAIN() {
  int n; cin >> n;
  vector<int> a(n);
  for (auto &i : a) cin >> i;
  int ans = 2e9;
  for (int t = 1; t < n; t++) {
    int s1 = 0, s2 = 0;
    for (int i = 0; i < n; i++) {
      if (i < t) s1 += a[i];
      else s2 += a[i];
    }
    ans = min(ans, abs(s1 - s2));
  }
  cout << ans << '\n';
}

signed main() {
#ifdef _DEBUG
  // freopen("in" , "r", stdin );
  // freopen("out", "w", stdout);
#endif
  ios::sync_with_stdio(0); cin.tie(0);
  int T = 1;
  // cin >> T;
  while (T--) MAIN();
}
