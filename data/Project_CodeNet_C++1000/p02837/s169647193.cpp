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
  vector<vii> v(n);
  rep(i, n) {
    int a;
    cin >> a;
    v[i].resize(a);
    rep(j, a) {
      cin >> v[i][j].fi >> v[i][j].se;
      v[i][j].fi--;
    }
  }

  int mx = 0;
  rep(i, 1 << n) {
    bool ok = true;

    rep(j, n) {
      if (i >> j & 1) {
        for (auto& k : v[j]) {
          if ((i >> k.fi & 1) != k.se) ok = false;
        }
      }
    }

    if (ok) mx = max(mx, __builtin_popcount(i));
  }
  cout << mx;

  return 0;
}
