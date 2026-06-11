#include <bits/stdc++.h>
using namespace std;

// #define int ll
using ll = long long;
using vi = vector<int>;
using vvi = vector<vi>;
using si = set<int>;
using ii = pair<int, int>;
using vii = vector<ii>;

#define fastio    ios::sync_with_stdio(0); cin.tie(0)
#define rep(i, n) for (int i = 0; i < n; i++)
#define dotc()    int tcs; if (cin >> tcs) rep(tc, tcs)
#define sz(x)     (int)x.size()
#define eb        emplace_back
#define pb        push_back
#define mp        make_pair
#define all(x)    x.begin(), x.end()
#define rall(x)   x.rbegin(), x.rend()
#define fi        first
#define se        second

int inf(0x3fffffff);
int mod(1000000007);
double pi(acos(-1.0));

int32_t main() {
  fastio;
#ifdef LOCAL
  freopen("io\\in.txt", "r", stdin);
  freopen("io\\out.txt", "w", stdout);
#endif

  int n;
  cin >> n;
  vvi cnt(10, vi(10));
  for (int i = 1; i < 10; i++) if (i <= n) cnt[i][i]++;
  
  for (int i = 1; i < 10; i++) {
    for (int j = 1; j < 10; j++) {
      bool ok = true;
      for (int k = 0, m = 1; ok; k++, m *= 10) {
        for (int l = 0; l < m; l++) {
          int cur = j, r = 10;
          for (int t = l; t; r *= 10, t /= 10) {
            cur += t % 10 * r;
          }
          cur += i * m * 10;
          if (cur > n) {
            ok = false;
            break;
          }
          // cout << i << ' ' << j << ' ' << cur << endl;
          cnt[i][j]++;
        }
      }
    }
  }

  ll tot = 0;
  for (int i = 1; i <= n; i++) {
    int f = i, e = i % 10;
    while (f > 9) f /= 10;
    tot += cnt[e][f];
  }
  cout << tot;

  return 0;
}
