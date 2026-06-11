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
  int ans = 0;
  for (int i = 1; i < n - 1; i++) {
    if (a[i - 1] < a[i] && a[i] < a[i + 1]) ans++;
    if (a[i - 1] > a[i] && a[i] > a[i + 1]) ans++;
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
