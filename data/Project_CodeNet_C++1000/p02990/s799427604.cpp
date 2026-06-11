#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using PII = pair<int, int>;
using VI = vector<int>;

const int N = 4005;
const ll mod = 1e9 + 7;
ll choose[N][N];

ll part(int n, int p) {
  if (n < 0) return 0;
  return choose[n + p - 1][p - 1];
}

int main() {
#ifdef LOCAL_EXEC
//	freopen("sample.in", "r", stdin);
//	freopen("sample.out", "w", stdout);
#else
  ios_base::sync_with_stdio(false); cin.tie(NULL);
#endif

  for (int n = 0; n < N; n++) {
    choose[n][0] = choose[n][n] = 1;
    for (int r = 1; r < n; r++) {
      choose[n][r] = (choose[n - 1][r] + choose[n - 1][r - 1]) % mod;
    }
  }

  int n, k; cin >> n >> k;
  int R = n - k, B = k;
  for (int i = 1; i <= k; i++) {
    ll ans = part(R - (i - 1), i + 1) * part(B - i, i) % mod;
    cout << ans << '\n';
  }

  return 0;
}
