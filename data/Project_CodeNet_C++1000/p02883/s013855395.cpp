#include <bits/stdc++.h>
using namespace std;
#ifdef DEBUG
#define FPEN freopen("in.txt", "r", stdin);
#else
#define FPEN
#endif
const int maxn = 200009;
typedef long long i64;
typedef pair<i64, i64> pi64;
typedef pair<int, int> pi;
const i64 MOD = 119 << 23 | 1;
class {
 public:
  i64 a[maxn], b[maxn];
  i64 n, k;
  void solve() {
    cin >> n >> k;
    for (int i = 0; i < n; ++i) cin >> a[i];
    for (int i = 0; i < n; ++i) cin >> b[i];
    sort(a, a + n);
    sort(b, b + n);
    i64 l = 0, r = 1e12;
    while (l < r) {
      i64 mid = l + r >> 1;
      if (ok(mid)) {
        r = mid;
      } else {
        l = mid + 1;
      }
    }
    cout << l;
  }
  bool ok(i64 Max) {
    i64 K = k;
    for (int i = n - 1; i >= 0; --i) {
      if (a[i] * b[n - 1 - i] <= Max) {
        continue;
      }
      i64 nwa = Max / b[n - 1 - i];
      if (K < a[i] - nwa) {
        return false;
      }
      K -= a[i] - nwa;
    }
    return true;
  }
} NSPACE;
int main() {
  FPEN;
  ios_base::sync_with_stdio(false);
  cout.tie(0);
  cin.tie(0);
  NSPACE.solve();
}