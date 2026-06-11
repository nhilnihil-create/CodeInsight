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

  ll n;
  cin >> n;

  vector<queue<ll>> que(n);
  rep(i, n) {
    rep(_, n - 1) {
      ll a;
      cin >> a;
      a--;
      que[i].push(a);
    }
  }

  set<P> games;

  auto chk = [&](ll x) {
    if (que[x].empty()) return;
    ll y = que[x].front();
    if (que[y].front() == x) {
      if (x > y) swap(x, y);
      games.insert(P(x, y));
    }
    return;
  };

  rep(i, n) chk(i);

  ll tsukaday = 0;
  while (!games.empty()) {
    tsukaday++;
    set<P> pgames;
    swap(games, pgames);
    for (P p : pgames) {
      que[p.first].pop();
      que[p.second].pop();
    }
    for (P p : pgames) {
      chk(p.first);
      chk(p.second);
    }
  }

  bool ok = true;
  rep(i, n) if (!que[i].empty()) {
    ok = false;
    break;
  }

  if(!ok) tsukaday = -1;
  cout << tsukaday << endl;

  return 0;
}
