#include <bits/stdc++.h>
using namespace std;

#define int long long

#define ii pair<int,int>
#define fi first
#define sc second

#define all(x) (x).begin(),(x).end()

signed main() {
#ifdef _DEBUG
  // freopen("in" , "r", stdin );
  // freopen("out", "w", stdout);
#endif
  ios::sync_with_stdio(0); cin.tie(0);
  int n, k, q;
  cin >> n >> k >> q;
  vector<int> a(n + 2);
  a[0] = k;
  for (int i = 1; i <= q; i++) {
    int t; cin >> t;
    a[1] += -1;
    a[t] +=  1;
    a[t + 1] += -1;
  }
  for (int i = 1; i <= n; i++) {
    a[i] += a[i - 1];
    if (a[i] <= 0) {
      cout << "No" << '\n';
    } else {
      cout << "Yes" << '\n';
    }
  }
}
