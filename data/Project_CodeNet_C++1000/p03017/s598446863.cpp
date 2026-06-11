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
  int n, a, b, c, d;
  cin >> n >> a >> b >> c >> d;
  string s; cin >> s;
  s = "#" + s;
  for (int i = a; i < c; i++) {
    if (s.substr(i, 2) == "##") {
      cout << "No" << '\n';
      return;
    }
  }
  for (int i = b; i < d; i++) {
    if (s.substr(i, 2) == "##") {
      cout << "No" << '\n';
      return;
    }
  }
  if (c < d) {
    cout << "Yes" << '\n';
    return;
  }
  for (int i = max(1ll, b - 1); i <= min(n - 2, d - 1); i++) {
    if (s.substr(i, 3) == "...") {
      cout << "Yes" << '\n';
      return;
    }
  }
  cout << "No" << '\n';
}

signed main() {
  ios::sync_with_stdio(0); cin.tie(0);
  int T = 1;
  // cin >> T;
  while (T--) MAIN();
}
