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
  void solve() {
    int n, k;
    cin >> n >> k;
    map<int, queue<int>> mp;
    mp[0].push(0);
    i64 ans = 0, sum = 0;
    for (int i = 1; i <= n; ++i) {
      int t;
      cin >> t;
      sum += t;
      int v = (sum - i) % k;
      while (mp[v].size() && i - mp[v].front() >= k) {
        mp[v].pop();
      }
      ans += mp[v].size();
      mp[v].push(i);
    }
    cout << ans << '\n';
  }
} NSPACE;
int main() {
  FPEN;
  ios_base::sync_with_stdio(false);
  cout.tie(0);
  cin.tie(0);
  NSPACE.solve();
}