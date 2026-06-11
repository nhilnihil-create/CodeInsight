#include <bits/stdc++.h>
using namespace std;

// #define int ll
using ll = long long;
using vi = vector<int>;
using vvi = vector<vi>;
using si = set<int>;
using ii = pair<int, int>;
using vii = vector<ii>;

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
  ios::sync_with_stdio(0);
  cin.tie(0);
#ifdef LOCAL
  freopen("io\\in.txt", "r", stdin);
  freopen("io\\out.txt", "w", stdout);
#endif

  int x, y, a, b, c;
  cin >> x >> y >> a >> b >> c;
  vi p(a), q(b), r(c);
  rep(i, a) cin >> p[i];
  rep(i, b) cin >> q[i];
  rep(i, c) cin >> r[i];
  sort(rall(p));
  sort(rall(q));
  sort(rall(r));

  vi v(x + y);
  copy(p.begin(), p.begin() + x, v.begin());
  copy(q.begin(), q.begin() + y, v.begin() + x);
  sort(all(v));

  ll sum = accumulate(all(v), 0ll);
  rep(i, c) {
    if (r[i] > v[i]) sum += r[i] - v[i];
    else break;
  }

  cout << sum;

  return 0;
}
