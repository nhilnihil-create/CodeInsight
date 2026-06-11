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

  int n, k;
  cin >> n >> k;
  vi a(n);
  rep(i, n) {
    int x;
    cin >> x;
    a[max(0, i - x)]++;
    if (i + x + 1 < n) a[i + x + 1]--;
  }

  vi p(n);
  partial_sum(all(a), p.begin());

  rep(i, k - 1) {
    vi b(n);
    rep(i, n) {
      b[max(0, i - p[i])]++;
      if (i + p[i] + 1 < n) b[i + p[i] + 1]--;
    }
    
    partial_sum(all(b), p.begin());
    bool ok = true;
    rep(j, n) if (p[j] != n) {
      ok = false;
      break;
    }
    if (ok) break;
  }
  rep(j, n) cout << p[j] << ' ';

  return 0;
}
