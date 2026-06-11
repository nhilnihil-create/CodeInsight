#include <bits/stdc++.h>
typedef long long ll;
typedef long double ld;
using namespace std;
#define F first
#define S second
#define pb push_back
#define all(x) (x).begin(), (x).end()
#define SZ(x) (int)(x).size()
#define int ll

signed main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);
  int n;
  cin >> n;
  vector<pair<int, int>> a(n);
  for (int i = 0; i < n; i++) {
    cin >> a[i].F >> a[i].S;
    a[i] = {a[i].F + a[i].S, 2 * a[i].S};
  }
  sort(all(a));
  vector<int> dp(n + 1), mx(n + 1);
  dp[0] = 0;
  int inf = int(2e9) + 7;
  for (int i = 1; i <= n; i++) {
    int pos = upper_bound(all(a), make_pair(a[i - 1].F - a[i - 1].S, inf)) - a.begin();
    dp[i] = mx[pos] + 1;
    mx[i] = max(mx[i - 1], dp[i]);
  }
  cout << mx[n] << '\n';
} 