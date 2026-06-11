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
  map<char, string> m;
  m['2'] = m['4'] = m['5'] = m['7'] = m['9'] = "hon";
  m['0'] = m['1'] = m['6'] = m['8'] = "pon";
  m['3'] = "bon";
  cout << m[s.back()] << '\n';
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
