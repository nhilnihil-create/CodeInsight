
/*
	@・ω・@
*/

/*****/

# include <iostream>
# include <vector>
# include <algorithm>
# include <string>
# include <sstream>
# include <cmath>
# include <queue>
# include <stack>
# include <map>
# include <iomanip>	//cout << fixed << setprecision(桁数);
# include <stdexcept>
# include <functional>

//#define int long long

using namespace std;
using ll = long long;
using ld = long double;
using pll = pair<long long, long long>;
template<class T> using vec = vector<T>;

#define debug(x) std::cerr << x
#define debugln(x) std::cerr << x << "\n"
#define debuglntab(n, x) std::cerr << strMulti('\t',n) << x << "\n"
#define debug_cout(x) std::cerr << #x << " = "; _debug_cout(x)
#define debug_tabcout(n, x) std::cerr << strMulti('\t',n) << #x << " = "; _debug_cout(x)
#define debug_headcout(h, x) std::cerr << h << " = "; _debug_cout(x)
#define debug_tabheadcout(n, h, x) std::cerr << strMulti('\t',n) << h << " = "; _debug_cout(x)

#define rep(i, n) for(int i=0, i##_len=(n); i<i##_len; ++i)
#define rep1(i, n) for(int i=1, i##_len=(n); i<=i##_len; ++i)
#define rrep(i, n) for(int i=(n)-1; i >= 0; --i)
#define rrep1(i, n) for(int i=(n); i > 0; --i)
#define step(i, a, n) for(int i=(a), i##_len=(a)+(n); i<i##_len; ++i)
#define rstep(i, a, n) for(int i=(a)+(n)-1, i##_len=(a); i>=i##_len; --i)
#define range(i, a, b) for(int i=(a), i##_len=(b); i<i##_len; ++i)
#define rrange(i, a, b) for(int i=(b)-1, i##_len=(a); i>=i##_len; --i)

#define repll(i, n) for(ll i=0, i##_len=(n); i<i##_len; ++i)
#define rep1ll(i, n) for(ll i=1, i##_len=(n); i<=i##_len; ++i)
#define rrepll(i, n) for(ll i=(n)-1; i >= 0; --i)
#define rrep1ll(i, n) for(ll i=(n); i > 0; --i)
#define stepll(i, a, n) for(ll i=(a), i##_len=(a)+(n); i<i##_len; ++i)
#define rstepll(i, a, n) for(ll i=(a)+(n)-1, i##_len=(a); i>=i##_len; --i)
#define rangell(i, a, b) for(ll i=(a), i##_len=(b); i<i##_len; ++i)
#define rrangell(i, a, b) for(ll i=(b)-1, i##_len=(a); i>=i##_len; --i)

#define all(x) (x).begin(), (x).end()
#define pair(a, b) make_pair(a, b)

template<class T> void _debug_cout(const T v, const string space = " ") { debugln(v); }
template<class T> void _debug_cout(const vector<T> ar, const string space = " ") { for (auto v : ar) { debug(v << space); } debugln(""); }
template<class T1, class T2> void _debug_cout(const vector<pair<T1, T2>> ar, const string space = " ") { rep(i, ar.size()) { debug(ar[i].first << "," << ar[i].second << space); } debugln(""); }
std::string strMulti(const char c, const int n) { std::string out = ""; for (int i = 0; i < n; i++) { out += c; } return out; }
std::string strMulti(const std::string t, const int n) { std::string out = ""; for (int i = 0; i < n; i++) { out += t; } return out; }

constexpr int INF = numeric_limits<int>::max();
constexpr ll INFL = numeric_limits<ll>::max();

template<class T> bool chmax(T& a, const T b) { if (a < b) { a = b; return true; } return false; }
template<class T> bool chmin(T& a, const T b) { if (a > b) { a = b; return true; } return false; }
template<class T> T divup(const T a, const T b) { if (a % b == 0) { return a / b; } return a / b + 1; }
template<class T> bool cmp_2nd(pair<T, T> a, pair<T, T> b) { if (a.second != b.second) { return a.second < b.second; } return a.first < b.first; }
ll mod_pow(ll x, ll n, const ll& p) { ll ret = 1; while (n > 0) { if (n & 1) { (ret *= x) %= p; } (x *= x) %= p; n >>= 1; } return ret; }
template<class T> T modinv(T a, const T& p) { T b = p, u = 1, v = 0; while (b) { T t = a / b; a -= t * b; swap(a, b); u -= t * v; swap(u, v); } u %= p; if (u < 0) { u += p; } return u; }
template<class T> T math_P(T m, T n) { T ret = 1; for (T i = m; i > m - n; i--) { ret *= i; } return ret; }
template<class T> T math_C(T m, T n) { T ret = math_P(m, n); for (T i = 2; i <= n; i++) { ret /= i; } return ret; }
ll extended_euclidean(ll u, ll v) { ll r0 = u; ll r1 = v; ll s0 = 1; ll s1 = 0; ll t0 = 0; ll t1 = 1; while (r1 != 0) { ll q = r0 / r1; ll r = r0 - q * r1; ll s = s0 - q * s1; ll t = t0 - q * t1; r0 = r1; s0 = s1; t0 = t1; r1 = r; s1 = s; t1 = t; } if (t0 < 0) { return t0 + u; } else { return t0; } }
ll math_C_mod(ll n, ll c, const ll& p) { ll upe = 1; ll dow = 1; for (ll i = 1; i < c + 1; ++i) { upe = upe * n % p; dow = dow * i % p; n -= 1; } return (upe * extended_euclidean(p, dow)) % p; }
//ll math_P_mod(ll m, ll n, const ll& p) { ll ret = 1; for (ll i = m; i > m - n; i--) { ret = (ret * i) % p; }return ret; }
//ll math_C_mod(ll m, ll n, const ll& p) { ll ret = math_P_mod(m, n, p); ll div = 1; for (ll i = 2; i <= n; i++) { div = (div * i) % p; }ret = (ret * modinv(div, p)) % p; return ret; }
template<class T> T math_gcd(T a, T b) { if (b == 0) { return a; } else { return math_gcd(b, a % b); } }
template<class T> T SumStep(T a, T n, T d) { return n * (2 * a + (n - 1) * d) / 2; }
template<class T> T SumRange(T a, T b, T d) { return SumStep(a, (b - a) / d, d); }

constexpr ll MOD = 1000000007;	// 10^9+7

/*****/

void Main()
{
	ll n, k;
	cin >> n >> k;

	vec<ll> gcds(k + 1);
	rrep1ll(i, k)
	{
		ll cnt = k / i;

		gcds[i] = mod_pow(cnt, n, MOD);

		ll m = 0;
		for (ll j = i * 2; j <= k; j += i)
		{
			m += gcds[j];
			m %= MOD;
		}

		//debug_cout(m);

		gcds[i] -= m;

		while (gcds[i] < 0)
		{
			gcds[i] += MOD;
		}
	}

	//debug_cout(gcds);

	ll sum = 0;
	for (int i = 0; i < k + 1; ++i)
	{
		sum += gcds[i] * i;
		sum %= MOD;
	}

	cout << sum;
}

/*****/

int main()
{
	std::ios::sync_with_stdio(false);
	std::cin.tie(0);

	std::cout << std::fixed << std::setprecision(10);

	/**
	while (true)
	{
		Main();
		std::cerr << flush;
		cout << endl;
	}
	/*/
	Main();
	std::cerr << flush;
	cout << endl;
	/**/

	return 0;
}
