#include <bits/stdc++.h>
using namespace std;

// ----------- define --------------
#define int long long
#define vi vector<int>
#define vc vector<char>
#define ii pair<int,int>
#define fi first
#define sc second
#define stoi stoll
#define all(x) (x).begin(),(x).end()
#define get_bit(x, k) ((x >> k) & 1)
// ---------------------------------

void MAIN() {
  int n; cin >> n;
  string s;
  cin >> s;
  int r = 0;
  for (auto &i : s) {
    if (i == 'R') r++;
  }
  int c = 0;
  for (int i = 0; i < n; i++) {
    if (i < r && s[i] == 'R') c++;
  }
  cout << r - c << '\n';
}

signed main() {
  ios::sync_with_stdio(0); cin.tie(0);
  int T = 1;
  // cin >> T;
  while (T--) MAIN();
}
