#include <bits/stdc++.h>
#define rep(i, n) for (ll i = 0; i < (ll)(n); ++i)
#define rep2(i, s, n) for (ll i = s; i < (ll)(n); i++)
#define repr(i, n) for (ll i = n; i >= 0; i--)
#define fi first
#define sc second
#define pb push_back
#define COUT(x) cout << (x) << endl
#define COUTF(x) cout << setprecision(15) << (x) << endl
#define ENDL cout << endl
#define DF(x) x.erase(x.begin())  // 先頭文字削除
#define ALL(x) x.begin(), x.end()
#define SORT(x) sort(ALL(x))
#define REVERSE(x) reverse(ALL(x))
#define ANS cout << ans << endl
#define RETURN(x)    \
  cout << x << endl; \
  return 0
clock_t CLOCK;
#define START_TIMER CLOCK = clock()
#define SHOW_TIMER cerr << "time: " << (ld)(clock() - CLOCK) / 1000000 << endl
#define init() \
  cin.tie(0);  \
  ios::sync_with_stdio(false)
#define debug(x) cerr << "[debug] " << #x << ": " << x << endl;
#define debugV(v)                       \
  cerr << "[debugV] " << #v << ":";     \
  rep(i, v.size()) cerr << " " << v[i]; \
  cerr << endl;
using namespace std;
using ll = long long;
using ld = long double;
using vll = vector<ll>;
using vvll = vector<vector<ll>>;
using mll = map<ll, ll>;
using qll = queue<ll>;
using P = pair<ll, ll>;

constexpr ll INF = 0x3f3f3f3f3f3f3f3f;
constexpr ld PI = 3.141592653589793238462643383279;
ll get_digit(ll x) {
  return to_string(x).size();
}

ll gcd(ll x, ll y) {
  return y ? gcd(y, x % y) : x;
}

ll lcm(ll a, ll b) {
  return a / gcd(a, b) * b;
}

vector<P> factorize(ll n) {
  vector<P> result;
  for (ll i = 2; i * i <= n; ++i) {
    if (n % i == 0) {
      result.pb({i, 0});
      while (n % i == 0) {
        n /= i;
        result.back().second++;
      }
    }
  }
  if (n != 1) {
    result.pb({n, 1});
  }
  return result;
}

vll divisor(ll n) {
  vll ret;
  for (ll i = 1; i * i <= n; i++) {
    if (n % i == 0) {
      ret.push_back(i);
      if (i * i != n) ret.push_back(n / i);
    }
  }
  SORT(ret);
  return (ret);
}

signed main() {
  init();
  ll N, M;
  cin >> N >> M;

  vector<P> key;

  rep(i, M) {
    ll a, b;
    cin >> a >> b;
    ll s = 0;
    rep(j, b) {
      ll c;
      cin >> c;
      --c;
      s |= 1 << c;
    }
    key.pb({s, a});
  }

  vll dp(1 << N, INF);
  dp[0] = 0;
  rep(s, 1 << N) {
    rep(i, M) {
      ll t = s | key[i].first;
      ll cost = dp[s] + key[i].second;
      dp[t] = min(dp[t], cost);
    }
  }

  ll ans = dp.back();
  if (ans == INF) {
    COUT(-1);
    return 0;
  }
  ANS;
  return 0;
}