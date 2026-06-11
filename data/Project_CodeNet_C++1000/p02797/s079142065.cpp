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
  int n, k, s;
  cin >> n >> k >> s;
  for (int i = 0; i < n; i++) {
    if (i < k) cout << s << ' ';
    else {
      if (s == (int)(1e9)) cout << 1 << ' ';
      else cout << (int)(1e9) << ' ';
    }
  }
  cout << '\n';
}

signed main() {
  ios::sync_with_stdio(0); cin.tie(0);
  int T = 1;
  // cin >> T;
  while (T--) MAIN();
}
