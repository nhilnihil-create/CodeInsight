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
  char a, b;
  cin >> a >> b;
  string sa, sb;
  for (char i = '1'; i <= b; i++) {
    sa += a;
  }
  for (char i = '1'; i <= a; i++) {
    sb += b;
  }
  if (sa <= sb) cout << sa << '\n';
  else cout << sb << '\n';
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
