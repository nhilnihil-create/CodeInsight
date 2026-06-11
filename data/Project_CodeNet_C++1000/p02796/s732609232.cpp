#include <bits/stdc++.h>
using namespace std;

#define int long long

#define ii pair<int,int>
#define fi first
#define sc second

#define all(x) (x).begin(),(x).end()

void MAIN() {
  int n; cin >> n;
  vector<ii> a(n);
  for (auto &i : a) {
    int x, l;
    cin >> x >> l;
    i.sc = x - l;
    i.fi = x + l;
  }
  sort(all(a));
  // left = sc | right = fi
  int ans = 0, d = -2e9;
  for (auto &i : a) {
    if (i.sc >= d) {
      d = i.fi;
      ans++;
    }
  }
  cout << ans << '\n';
}

signed main() {
#ifdef _DEBUG
  // freopen("in" , "r", stdin );
#endif
  ios::sync_with_stdio(0); cin.tie(0);
  int T = 1;
  // cin >> T;
  while (T--) MAIN();
}
