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
const double PI = acos(-1.0);

#define REP(i, m, n) for (ll i = m; i < (ll)(n); ++i)
#define rep(i, n) REP(i, 0, n)
#define MP make_pair
#define MT make_tuple
#define YES(n) cout << ((n) ? "YES" : "NO") << endl
#define Yes(n) cout << ((n) ? "Yes" : "No") << endl
#define Possible(n) cout << ((n) ? "Possible" : "Impossible") << endl
#define possible(n) cout << ((n) ? "possible" : "impossible") << endl
#define Yay(n) cout << ((n) ? "Yay!" : ":(") << endl
#define all(v) v.begin(), v.end()
#define NP(v) next_permutation(all(v))
#define dbg(x) cerr << #x << ":" << x << endl;

vector<int> Dx = {0, 0, -1, 1, -1, 1, -1, 1, 0};
vector<int> Dy = {1, -1, 0, 0, -1, -1, 1, 1, 0};

int main()
{
  cin.tie(0);
  ios::sync_with_stdio(false);
  ll k, q;
  cin >> k >> q;
  ll d[5000];
  rep(i, k) cin >> d[i];
  rep(qi, q)
  {
    ll n, x, m;
    cin >> n >> x >> m;
    ll dm[5000];
    rep(i, k) dm[i] = d[i] % m;
    ll d_sum = 0;
    rep(i, k) d_sum += dm[i];
    ll cnt = 0;
    //a[i] = a[i+1]
    ll zero = 0;
    rep(i, k) zero += dm[i] == 0;
    cnt += ((n - 1) / k) * zero;
    rep(i, (n - 1) % k) cnt += dm[i] == 0;
    //a[i] > a[i+1]
    ll a = x + ((n - 1) / k) * d_sum;
    rep(i, (n - 1) % k) a += dm[i];
    cnt += (a / m) - (x / m);
    cout << n - 1 - cnt << endl;
  }

  return 0;
}
