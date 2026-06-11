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
  string s;
  cin >> s;
  if (s.size() % 2) {
    cout << "No" << '\n';
    return;
  }
  for (int i = 0; i < s.size(); i++) {
    if ((i % 2 == 0 && s[i] != 'h') || (i % 2 && s[i] != 'i')) {
      cout << "No" << '\n';
      return;
    }
  }
  cout << "Yes" << '\n';
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
