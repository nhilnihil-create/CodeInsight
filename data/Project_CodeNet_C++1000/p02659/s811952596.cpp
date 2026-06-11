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
  int a; string s;
  cin >> a >> s;
  int b = stoi(s.substr(0, s.size() - 3)) * 100 + stoi(s.substr(s.size() - 2, 2));
  cout << a * b / 100 << '\n';
}

signed main() {
  ios::sync_with_stdio(0); cin.tie(0);
  int T = 1;
  // cin >> T;
  while (T--) MAIN();
}
