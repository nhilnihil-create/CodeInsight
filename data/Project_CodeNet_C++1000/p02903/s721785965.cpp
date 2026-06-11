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
  int n, m, a, b;
  cin >> n >> m >> a >> b;
  for (int i = 1; i <= n; i++) {
    for (int j = 1; j <= m; j++) {
      cout << ((i <= b) ^ (j <= a));
    }
    cout << '\n';
  }
}

signed main() {
  ios::sync_with_stdio(0); cin.tie(0);
  int T = 1;
  // cin >> T;
  while (T--) MAIN();
}
