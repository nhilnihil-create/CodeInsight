#include <bits/stdc++.h>
using namespace std;

#define int long long

#define ii pair<int,int>
#define fi first
#define sc second

#define all(x) (x).begin(),(x).end()

const int N = 55;

int n, m, q;
int a[N], b[N], c[N], d[N], e[N];

int ans = 0;

void check() {
  int sum = 0;
  for (int i = 1; i <= q; i++) {
    if (e[b[i]] - e[a[i]] == c[i]) {
      sum += d[i];
    }
  }
  ans = max(ans, sum);
}

void brute(int i) {
  for (int j = e[i - 1]; j <= m; j++) {
    e[i] = j;
    if (i == n) check();
    else brute(i + 1);
  }
}

void solve() {
  cin >> n >> m >> q;
  for (int i = 1; i <= q; i++) {
    cin >> a[i] >> b[i] >> c[i] >> d[i];
  }
  e[0] = 1;
  brute(1);
  cout << ans << '\n';
}

signed main() {
#ifdef _DEBUG
  freopen("in" , "r", stdin );
  // freopen("out", "w", stdout);
#endif
  ios::sync_with_stdio(0); cin.tie(0);
  int T = 1;
  // cin >> T;
  while (T--) solve();
}
