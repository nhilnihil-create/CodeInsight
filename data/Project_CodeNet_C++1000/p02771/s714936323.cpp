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
  vector<int> a(3);
  for (auto &i : a) cin >> i;
  sort(all(a));
  if ((a[1] == a[0] && a[1] != a[2]) || (a[1] == a[2] && a[1] != a[0])) {
    cout << "Yes" << '\n';
  }
  else {
    cout << "No" << '\n';
  }
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
