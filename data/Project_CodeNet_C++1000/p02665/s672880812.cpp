#include <algorithm>
#include <bitset>
#include <cmath>
#include <complex>
#include <cstring>
#include <iomanip>
#include <iostream>
#include <list>
#include <map>
#include <numeric>
#include <queue>
#include <regex>
#include <set>
#include <stack>
#include <string>
#include <vector>

const int MOD = 1e9 + 7;
const int iINF = 2147483647 / 2;
const long long int llINF = 9223372036854775807 / 2;

using namespace std;
using ll = long long int;
using vl = vector<ll>;
using vvl = vector<vector<ll>>;
using vvvl = vector<vector<vector<ll>>>;

typedef pair<ll, ll> pll;
bool paircomp(const pll &a, const pll &b) {
  if (a.first == b.first)
    return a.second < b.second;
  return a.first < b.first;
}

#define REP(i, n) for (ll i = 0; i < (n); i++)
#define RREP(i, n) for (ll i = (n)-1; i >= 0; i--)
#define FOR(i, a, b) for (ll i = (a); i < (b); i++)
#define AUTO(i, m) for (auto &i : m)
#define ALL(a) (a).begin(), (a).end()
#define MAX(vec) *std::max_element(vec.begin(), vec.end())
#define MIN(vec) *std::min_element(vec.begin(), vec.end())
#define ARGMAX(vec)                                                            \
  std::distance(vec.begin(), std::max_element(vec.begin(), vec.end()))
#define ARGMIN(vec)                                                            \
  std::distance(vec.begin(), std::min_element(vec.begin(), vec.end()))
#define REV(T) greater<T>()
#define PQ(T) priority_queue<T, vector<T>, greater<T>>
#define VVL(a, b, c) vector<vector<ll>>(a, vector<ll>(b, c))
#define VV(T, a, b, c) vector<vector<T>>(a, vector<T>(b, c))
#define VVVL(a, b, c, d)                                                       \
  vector<vector<vector<ll>>>(a, vector<vector<ll>>(b, vector<ll>(c, d)))
#define VVV(T, a, b, c, d)                                                     \
  vector<vector<vector<T>>>(a, vector<vector<T>>(b, vector<T>(c, d)))
#define SP(a) setprecision(a)
#define SQRT(a) sqrt((long double)(a))
#define DPOW(a, b) pow((long double)(a), (long double)(b))
#define UNIQUE(vec)                                                            \
  do {                                                                         \
    sort(ALL((vec)));                                                          \
    (vec).erase(std::unique(ALL((vec))), (vec).end());                         \
  } while (0)

ll POW(ll n, ll m) {
  if (m == 0) {
    return 1;
  } else if (m % 2 == 0) {
    ll tmp = POW(n, m / 2);
    return (tmp * tmp);
  } else {
    return (n * POW(n, m - 1));
  }
}

int dx[4] = {1, 0, -1, 0};
int dy[4] = {0, 1, 0, -1};

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  ll N;
  cin >> N;
  vl A(N + 1);
  REP(i, N + 1) cin >> A[i];
  if (N == 0 && A[0] == 1) {
    cout << 1 << endl;
    return 0;
  } else if (A[0] != 0) {
    cout << -1 << endl;
    return 0;
  }

  //そもそもできるかチェック
  ll n = 0;
  for (ll i = N; i > 0; i--) {
    n = (A[i] + n + 1) / 2;
  }
  if (n > 1) {
    cout << -1 << endl;
    return 0;
  }

  vl DP(N + 2, 0);
  RREP(i, N + 1) { DP[i] = DP[i + 1] + A[i]; }
  ll now = 0;
  ll ans = 0;
  ll par = 1;
  for (ll i = 0; i <= N; i++) {
    ll po = A[i] + DP[i + 1];
    if (i > 0)
      po = min(po, par * 2);
    else
      po = 1;
    par = po - A[i];
    ans += po;
    // cout << po << endl;
  }
  cout << ans << endl;
  return 0;
}
