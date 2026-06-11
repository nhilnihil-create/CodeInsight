#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define FOR(i, a, b) for (int i = (a); i < (b); ++i)
#define REP(i, n) for (int i = (0); i < (n); ++i)
#define ALL(obj) (obj).begin(), (obj).end()
#define DEBUG(val) cout << #val << " : " << val << endl
#define MOD 1000000007

int main() {
  int n;
  int a[55][3];
  cin >> n;
  REP(i, n) { cin >> a[i][0] >> a[i][1]; }
  int sum = 0;
  REP(i, n) {
    REP(j, n) {
      if (j == i) continue;
      int p = a[i][0] - a[j][0];
      int q = a[i][1] - a[j][1];
      int tmp_sum = 0;
      REP(ni, n) {
        REP(nj, n) {
          if (nj == ni) continue;
          if (a[ni][0] == a[nj][0] - p && a[ni][1] == a[nj][1] - q) {
            tmp_sum++;
          }
        }
      }
      sum = max(sum, tmp_sum);
    }
  }
  cout << n - sum << endl;
}