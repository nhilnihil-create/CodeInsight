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
  vector<int> a(n + 1);
  for (int i = 1; i <= n; i++) {
    cin >> a[i];
  }
  vector<int> d(n + 1), res;
  for (int i = n; i >= 1; i--) {
    int s = 0;
    for (int j = i; j <= n; j += i) {
      s += d[j];
    }
    if (s % 2 != a[i]) {
      d[i] = 1;
      res.push_back(i);
    }
  }
  cout << res.size() << '\n';
  for (auto &i : res) cout << i << ' ';
  if (res.size()) cout << '\n';
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
