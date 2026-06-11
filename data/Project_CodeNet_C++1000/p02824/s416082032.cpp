#include <limits.h>
#include <math.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include <algorithm>
#include <cassert>
#include <cfloat>
#include <complex>
#include <functional>
#include <iomanip>
#include <iostream>
#include <map>
#include <numeric>
#include <queue>
#include <regex>
#include <set>
#include <stack>
#include <string>
#include <unordered_map>
#include <vector>

using namespace std;

#define chmax(x, y) x = max(x, y)
#define chmin(x, y) x = min(x, y)
#define rep(i, n) for (ll i = 0; i < (n); ++i)
#define repLRE(i, l, r) for (ll i = (l); i <= (r); ++i)
#define rrepLRE(i, l, r) for (ll i = (l); i >= (r); --i)
#define Sort(v) sort(v.begin(), v.end())
#define rSort(v) sort(v.rbegin(), v.rend())
#define Reverse(v) reverse(v.begin(), v.end())
#define Lower_bound(v, x) \
  distance(v.begin(), lower_bound(v.begin(), v.end(), x))
#define Upper_bound(v, x) \
  distance(v.begin(), upper_bound(v.begin(), v.end(), x))

using ll = long long;
using ull = unsigned long long;
using P = pair<ll, ll>;
using T = tuple<ll, ll, ll>;
using vll = vector<ll>;
using vP = vector<P>;
using vT = vector<T>;
using vvll = vector<vector<ll>>;
using vvP = vector<vector<P>>;
using dqll = deque<ll>;

ll dx[9] = {-1, 1, 0, 0, -1, -1, 1, 1, 0};
ll dy[9] = {0, 0, -1, 1, -1, 1, -1, 1, 0};

/* Macros reg. ends here */

const ll INF = 1LL << 50;

int main() {
  // ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
  cout << fixed << setprecision(15);

  ll n, m, v, p;
  cin >> n >> m >> v >> p;
  vll as(n), bs(n);
  rep(i, n) cin >> as[i];
  rSort(as);

  bs[0] = 1;
  rep(i, n - 1) {
    bs[i + 1] = bs[i];
    if (as[i + 1] < as[i]) bs[i + 1] = i + 2;
  }

  vll csum(n + 1);
  csum[0] = 0;
  rep(i, n) csum[i + 1] = csum[i] + as[i];

  ll crescent1997 = 0;
  rep(i, n) {
    if (i + 1 <= p) {
      crescent1997++;
      continue;
    }
    if (as[p - 1] > as[i] + m) continue;
    ll vp = v - (p - 1) - (n - i);
    chmax(vp, 0LL);
    ll lhs = (as[i] + m) * (i - p + 1) - (csum[i] - csum[p - 1]);
    ll rhs = vp * m;
    if (lhs >= rhs) crescent1997++;
  }

  cout << crescent1997 << endl;

  return 0;
}
