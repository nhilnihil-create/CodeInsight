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
  const int V = 1000000;
  vector<int> f(V + 1, 0);
  int n; cin >> n;
  for (int i = 0; i < n; i++) {
    int t; cin >> t;
    f[t]++;
  }
  int ans = 0;
  for (int i = 1; i <= V; i++) {
    if (f[i] == 1) ans++;
    if (f[i]) {
      for (int j = i; j <= V; j += i) f[j] = 0;
    }
  }
  cout << ans << '\n';
}

signed main() {
  // ios::sync_with_stdio(0); cin.tie(0);
  int T = 1;
  // cin >> T;
  while (T--) MAIN();
}
