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
  int x; cin >> x;
  if (x < 600) cout << 8 << '\n';
  else if (x < 800) cout << 7 << '\n';
  else if (x < 1000) cout << 6 << '\n';
  else if (x < 1200) cout << 5 << '\n';
  else if (x < 1400) cout << 4 << '\n';
  else if (x < 1600) cout << 3 << '\n';
  else if (x < 1800) cout << 2 << '\n';
  else if (x < 2000) cout << 1 << '\n';
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
