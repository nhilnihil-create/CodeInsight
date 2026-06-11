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
  vector<int> a(n);
  for (auto &i : a) cin >> i;
  sort(all(a), greater<int>());
  int t = n - 2, s = a[0];
  for (int i = 1; i < n; i++) {
    if (t >= 2) {
      s += a[i] * 2;
      t -= 2;
    }
    else if (t >= 1) {
      s += a[i];
      t -= 1;
    }
  }
  cout << s << '\n';
}

signed main() {
  ios::sync_with_stdio(0); cin.tie(0);
  int T = 1;
  // cin >> T;
  while (T--) MAIN();
}
