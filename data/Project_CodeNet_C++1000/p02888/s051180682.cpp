#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define FOR(i, a, b) for (int i = (a); i < (b); ++i)
#define REP(i, n) for (int i = (0); i < (n); ++i)
#define ALL(obj) (obj).begin(), (obj).end()
#define chmin(a, b) a = min(a, b)
#define chmax(a, b) a = max(a, b)
#define vi vector<int>
#define vvi vector<vi>
#define P pair<int, int>
#define DEBUG(val) cout << #val << " : " << val << endl
#define MOD 1000000007

int main() {
  int n;
  cin >> n;
  vi d(n);
  REP(i, n) { cin >> d[i]; }
  sort(ALL(d));
  int ans = 0;
  REP(i, n - 2) {
    FOR(j, i + 1, n - 1) {
      FOR(k, j + 1, n) {
        if (d[k] < d[i] + d[j] && d[i] < d[k] + d[j] && d[j] < d[i] + d[k]) {
          ans++;
        }
      }
    }
  }
  cout << ans << endl;
}