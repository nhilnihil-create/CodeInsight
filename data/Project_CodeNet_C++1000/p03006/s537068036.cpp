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
  vector<ii> a(n);
  for (auto &i : a) cin >> i.fi >> i.sc;
  sort(all(a));
  map<ii, int> mem;
  for (int i = 0; i < n - 1; i++)
  for (int j = i + 1; j < n; j++) {
    mem[ii(a[j].fi - a[i].fi, a[j].sc - a[i].sc)]++;
  }
  int ans = 0;
  for (auto &i : mem) {
    ans = max(ans, i.sc);
  }
  cout << n - ans << '\n';
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
