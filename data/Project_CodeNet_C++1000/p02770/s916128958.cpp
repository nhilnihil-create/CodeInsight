#include <bits/stdc++.h>
#define REP(i, n) for (int i = 0; i < n; i++)
#define FOR(i, m, n) for (int i = m; i < n; i++)
#define ALL(v) (v).begin(), (v).end()
#define coutd(n) cout << fixed << setprecision(n)
#define ll long long int
#define vl vector<ll>
#define vi vector<int>
const int INF = 2147483647;
const ll MOD = 1000000007;

using namespace std;

int main() {
  int k, q;
  cin >> k >> q;
  vl d(k);
  REP(i, k) { cin >> d[i]; }
  REP(i, q) {
    int n, x, m;
    cin >> n >> x >> m;
    vl cum(k + 1), count(k + 1);
    cum[0] = 0LL;
    count[0] = 0LL;
    REP(i, k) {
      cum[i + 1] = cum[i] + (d[i] % m);
      count[i + 1] = count[i];
      if (d[i] % m == 0) {
        count[i + 1]++;
      }
    }
    x %= m;
    ll length = x + ((n - 1) / k) * cum[k] + cum[(n - 1) % k];
    ll zero = ((n - 1) / k) * count[k] + count[(n - 1) % k];
    ll ans = n - 1 - (length / m) - zero;
    cout << ans << endl;
  }
  return 0;
}
