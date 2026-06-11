#include <bits/stdc++.h>
using namespace std;
#define FOR(i, a, b) for (int i = a; i < (int)(b); i++)
#define REP(i, n) for (int i = 0; i < (int)(n); i++)
#define REP1(i, n) for (int i = 1; i <= (int)(n); i++)
#define all(x) (x).begin(), (x).end()
#define SZ(x) ((int)(x).size())
using ll = long long;

int main() {
  int n;
  cin >> n;
  vector<int> a(n);
  REP(i, n) { cin >> a[i]; }
  sort(all(a));
  vector<bool> flg(a[n - 1] + 1, false);
  REP(i, n) {
    if (!flg[a[i]]) {
      int k = 2 * a[i];
      while (k <= a[n - 1]) {
        flg[k] = true;
        k += a[i];
      }
    }
  }
  int ans = 0;
  REP(i, n) {
    if (i == 0) {
      if (!flg[a[i]] && a[i] != a[i + 1]) {
        ans++;
      }
    } else if (i == n - 1) {
      if (!flg[a[i]] && a[i] != a[i - 1]) {
        ans++;
      }
    } else if (!flg[a[i]] && a[i] != a[i - 1] && a[i] != a[i + 1]) {
      ans++;
    }
  }

  cout << ans << endl;
  return 0;
}
