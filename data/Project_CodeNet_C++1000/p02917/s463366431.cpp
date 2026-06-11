#include <bits/stdc++.h>
using namespace std;

#define int long long

#define ii pair<int,int>
#define fi first
#define sc second

#define all(x) (x).begin(),(x).end()

void chmin(int &a, int b) {
  if (a > b) a = b;
}

signed main() {
#ifdef _DEBUG
  // freopen("in" , "r", stdin );
  // freopen("out", "w", stdout);
#endif
  ios::sync_with_stdio(0); cin.tie(0);
  int n;
  cin >> n;
  vector<int> a(n, 2e9);
  for (int i = 0; i < n - 1; i++) {
    int t; cin >> t;
    chmin(a[i], t);
    chmin(a[i + 1], t);
  }
  int ans = 0;
  for (int i = 0; i < n; i++) {
    ans += a[i];
  }
  cout << ans << '\n';
}
