#include <bits/stdc++.h>
using namespace std;

// ----------- define --------------
#define int long long
#define vi vector<int>
#define ii pair<int,int>
#define fi first
#define sc second
#define stoi stoll
#define popcnt __builtin_popcount
#define getBit(x, k) ((x >> k) & 1)
#define all(x) (x).begin(),(x).end()
// ---------------------------------

void Main() {
  int n; cin >> n;
  vector<int> a(n);
  for (auto &i : a) cin >> i;
  int x = 0;
  for (int i = 0; i < n; i++) {
    if (i % 2) x -= a[i];
    else x += a[i];
  }
  for (int i = 0; i < n; i++) {
    cout << x << ' ';
    x = a[i] * 2 - x;
  }
  cout << '\n';
}

signed main() {
#ifdef _DEBUG
  // freopen("in" , "r", stdin );
  cerr << "- ---- -- ----- <3\n";
#endif
  cin.tie(0)->sync_with_stdio(0);
  int T = 1;
  // cin >> T;
  while (T--) Main();
}
