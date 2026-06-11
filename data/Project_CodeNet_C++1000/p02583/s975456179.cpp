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
  sort(all(a));
  int ans = 0;
  for (int i = 0; i < n - 2; i++)
  for (int j = i + 1; j < n - 1; j++)
  for (int k = j + 1; k < n; k++) {
    if (a[i] != a[j] && a[j] != a[k] && a[k] != a[i]) {
      if (a[k] < a[i] + a[j]) {
        ans++;
      }
    }
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
