#include <bits/stdc++.h>

using namespace std;

#define eb emplace_back
#define ii pair<int, int>
#define OK (cerr << "OK" << endl)
#define debug(x) cerr << #x " = " << (x) << endl
#define ff first
#define ss second
#define int long long
#define tt tuple<int, int, int, int>
#define all(x) x.begin(), x.end()
#define Matrix vector<vector<int>>
#define Mat(n, m, v) vector<vector<int>>(n, vector<int>(m, v))
#define endl '\n'

constexpr int INF = 2e18;
constexpr int MOD = 1e9 + 7;
constexpr int MAXN = 2e5 + 3;

int cnt(int k, int n) {
  while (n % k == 0) {
    n /= k;
  }
  return (n % k == 1);
}

signed main() {

  ios_base::sync_with_stdio(false);
  cin.tie(NULL);

  int t;

  t = 1;

  while (t--) {
    int n;
    cin >> n;
    if (n == 2)
      return cout << 1 << endl, 0;

    int ans = 1;
    for (int i = 1; i * i <= (n - 1); ++i) {
      if ((n - 1) % i == 0) {
        int l = i, r = (n - 1) / i;
        ans += 2 - (l == r || l == 1);
      }
    }

    for (int k = 2; k * k <= n; ++k) {
      if (n % k == 0) {
        ans += cnt(k, n);
      }
    }

    cout << ans << endl;
  }
}