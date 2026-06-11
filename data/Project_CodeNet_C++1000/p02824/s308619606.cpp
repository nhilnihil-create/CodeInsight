#pragma region Macros
#include <bits/stdc++.h>
using namespace std;
//#include <boost/multiprecision/cpp_int.hpp>
//using multiInt = boost::multiprecision::cpp_int;

using ll = long long int;
using ld = long double;
using pii = pair<int, int>;
using pll = pair<ll, ll>;
template <typename Q_type>
using smaller_queue = priority_queue<Q_type, vector<Q_type>, greater<Q_type>>;

const int MOD_TYPE = 1;
const ll MOD = (MOD_TYPE == 1 ? (ll)(1e9 + 7) : 998244353);
const int INF = (int)1e9;
const ll LINF = (ll)4e18;
const ld PI = acos(-1.0);
const ld EPS = 1e-11;

#define REP(i, m, n) for (ll i = m; i < (ll)(n); ++i)
#define rep(i, n) REP(i, 0, n)
#define MP make_pair
#define MT make_tuple
#define YES(n) cout << ((n) ? "YES" : "NO") << "\n"
#define Yes(n) cout << ((n) ? "Yes" : "No") << "\n"
#define Possible(n) cout << ((n) ? "Possible" : "Impossible") << "\n"
#define possible(n) cout << ((n) ? "possible" : "impossible") << "\n"
#define Yay(n) cout << ((n) ? "Yay!" : ":(") << "\n"
#define all(v) v.begin(), v.end()
#define NP(v) next_permutation(all(v))
#define dbg(x) cerr << #x << ":" << x << "\n";

vector<int> Dx = {0, 0, -1, 1, -1, 1, -1, 1, 0};
vector<int> Dy = {1, -1, 0, 0, -1, -1, 1, 1, 0};

#pragma endregion

int main()
{
  cin.tie(0);
  ios::sync_with_stdio(false);
  cout << setprecision(30) << setiosflags(ios::fixed);

  ll n, m, v, p;
  cin >> n >> m >> v >> p;
  vector<ll> a(n);
  rep(i, n) cin >> a[i];
  sort(all(a), greater<ll>());
  ll csum[100010];
  csum[0] = 0;
  rep(i, n) csum[i + 1] = csum[i] + a[i];

  auto f = [&](int l, int r, ll t) {
    if (l == r)
      return 0LL;
    ll lo = l - 1, hi = r;
    while (hi - lo > 1)
    {
      ll mi = (lo + hi) / 2;
      if (t - a[mi] <= m)
        lo = mi;
      else
        hi = mi;
    }
    ll res = 0;
    res += t * (lo - l + 1);
    res -= csum[lo + 1] - csum[l];
    res += (r - lo - 1) * m;
    return res;
  };
  
  ll ans = p - 1;
  REP(i, p - 1, n)
  {
    ll t = a[i] + m;
    if (t < a[p - 1])
      break;
    if (f(p - 1, i, t) + f(i + 1, n, t) >= m * (v - p))
      ans++;
  }
  cout << ans << endl;
  return 0;
}