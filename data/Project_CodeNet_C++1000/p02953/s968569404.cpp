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
  int n;
  cin >> n;
  vector<int> a(n + 1);
  for (int i = 1; i <= n; i++) {
    cin >> a[i];
    if (a[i] > a[i - 1]) a[i]--;
  }
  for (int i = 1; i <= n; i++) {
    if (a[i] < a[i - 1]) {
      cout << "No" << '\n';
      return 0;
    }
  }
  cout << "Yes" << '\n';
}
