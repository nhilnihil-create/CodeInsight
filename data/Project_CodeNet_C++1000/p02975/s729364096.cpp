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
  int zero = 1;
  for (auto &i : a) {
    cin >> i;
    if (i) zero = 0;
  }
  if (zero) {
    cout << "Yes" << '\n';
    return;
  }
  sort(all(a));
  if (n % 3) {
    cout << "No" << '\n';
    return;
  }
  int t = n / 3;
  for (int i = 0; i < t; i++) {
    if ((a[i] ^ a[i + t]) != a[i + t * 2]) {
      cout << "No" << '\n';
      return;
    }
    if (i && (a[i] != a[i - 1] || a[i + t] != a[i + t - 1])) {
      cout << "No" << '\n';
      return;
    }
  }
  cout << "Yes" << '\n';
}

signed main() {
  ios::sync_with_stdio(0); cin.tie(0);
  int T = 1;
  // cin >> T;
  while (T--) MAIN();
}
