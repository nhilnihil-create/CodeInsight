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

  ll n, k;
  cin >> n >> k;

  n += 2;
  vll hs(n, 0);
  rep(i, n - 1) cin >> hs[i + 1];
  hs[n - 1] = 0;

  vvll con(n, vll(n));
  rep(ii, n - 1) {
    repLRE(jj, ii + 1, n - 1) {
      con[ii][jj] = con[ii][jj - 1];
      if (hs[ii] != hs[jj]) con[ii][jj]++;
    }
  }

  vvll dp(n, vll(k + 1, INF));
  rep(kk, k + 1) dp[0][kk] = 0;
  repLRE(ii, 1, n - 1) {
    dp[ii][0] = dp[ii - 1][0] + max(0LL, hs[ii] - hs[ii - 1]);
    rep(kk, k + 1) {
      rep(jj, ii) {
        ll nkk = kk - con[jj][ii - 1];
        if (nkk >= 0)
          chmin(dp[ii][kk], dp[jj][nkk] + max(0LL, hs[ii] - hs[jj]));
      }
    }
  }

  cout << dp.back().back() << endl;

  return 0;
}
