#include <bits/stdc++.h>
using namespace std;

// ----------- define --------------
#define int long long
#define ii pair<int,int>
#define fi first
#define sc second
#define all(x) (x).begin(),(x).end()
// ---------------------------------

void MAIN() {
  int n, k;
  cin >> n >> k;
  vector<int> a(n);
  for (auto &i : a) cin >> i;
  sort(all(a));
  int ans = 0;
  for (int i = 0; i < n - k; i++) {
    ans += a[i];
  }
  cout << ans << '\n';
}

signed main() {
  ios::sync_with_stdio(0); cin.tie(0);
  int T = 1;
  // cin >> T;
  while (T--) MAIN();
}
