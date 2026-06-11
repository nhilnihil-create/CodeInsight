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
  if (is_sorted(all(a))) {
    cout << "YES" << '\n';
    return;
  }
  for (int i = 0; i < n - 1; i++)
  for (int j = i + 1; j < n; j++) {
    swap(a[i], a[j]);
    if (is_sorted(all(a))) {
      cout << "YES" << '\n';
      return;
    }
    swap(a[i], a[j]);
  }
  cout << "NO" << '\n';
  return;
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
