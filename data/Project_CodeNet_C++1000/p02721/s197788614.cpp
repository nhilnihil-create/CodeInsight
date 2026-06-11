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

signed main() {

  ios_base::sync_with_stdio(false);
  cin.tie(NULL);

  int t;

  // cin >> t;
  t = 1;

  while (t--) {
    int n;
    cin >> n;

    int k, c;
    cin >> k >> c;

    string s;
    cin >> s;

    vector<int> l(k), r(k);
    {
      int ptr = 0;
      int last = -1;
      for (int i = 0; ptr < k; ++i) {
        if (s[i] == 'x')
          continue;
        if (last >= 0 && last + c >= i)
          continue;
        l[ptr++] = i;
        last = i;
      }
    }

    {
      int ptr = k - 1;
      int last = -1;
      for (int i = n - 1; ptr >= 0; --i) {
        if (s[i] == 'x')
          continue;
        if (last >= 0 && i + c >= last)
          continue;
        last = i;
        r[ptr--] = i;
      }
    }

    for (int i = 0; i < k; ++i) {
      if (l[i] == r[i]) {
        cout << l[i] + 1 << endl;
      }
    }
  }
}