
/*
	@・ω・@ <れれですよ
*/

/*****/

# include <iostream>
# include <vector>
# include <algorithm>
# include <string>
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

#define debug(x) (std::cerr << x)
#define debugln(x) (std::cerr << x << "\n")
#define debug_tab(n, x) (std::cerr << strMulti("\t",n) << (x) << "\n")
#define debug_cout(x) (std::cerr << #x << " : " <<  (x) << "\n")
#define debug_coutVec(x) std::cerr << #x << " : "; _debug_coutVec(x)
#define debug_tabcout(n, x) (std::cerr << strMulti("\t",n) << #x << " : " <<  (x) << "\n")
#define debug_headcout(h, x) (std::cerr << h << " : " <<  (x) << "\n")
#define debug_tabheadcout(n, h, x) (std::cerr << strMulti("\t",n) << h << " : " <<  (x) << "\n")

#define rep(i, n) for(ll i=0, i##_len=(n); i<i##_len; ++i)
#define rep1(i, n) for(ll i=1, i##_len=(n); i<=i##_len; ++i)
#define rrep(i, n) for(ll i=(n)-1; i >= 0; --i)
#define rrep1(i, n) for(ll i=(n); i > 0; --i)
#define step(i, a, n) for(ll i=(a), i##_len=(a)+(n); i<i##_len; ++i)
#define rstep(i, a, n) for(ll i=(a)+(n)-1, i##_len=(a); i>=i##_len; --i)
#define range(i, a, b) for(ll i=(a), i##_len=(b); i<i##_len; ++i)
#define rrange(i, a, b) for(ll i=(b)-1, i##_len=(a); i>=i##_len; --i)
#define all(x) (x).begin(), (x).end()
#define pair(a, b) make_pair(a, b)
constexpr int INF = 2147483647;
template<class T> bool chmax(T& a, T b) { if (a < b) { a = b; return true; } return false; }
template<class T> bool chmin(T& a, T b) { if (a > b) { a = b; return true; } return false; }
template<class T> T divup(T a, T b) { if (a % b == 0) { return a / b; } return a / b + 1; }
std::string strMulti(std::string t, int n) { std::string out = ""; for (int i = 0; i < n; i++) { out += t; } return out; }
template<class T> T math_P(T m, T n) { T ret = 1; for (T i = m; i > m - n; i--) { ret *= i; } return ret; }
template<class T> T math_C(T m, T n) { T ret = math_P(m, n); for (T i = 2; i <= n; i++) { ret /= i; } return ret; }
template<class T> bool cmp_2nd(pair<T, T> a, pair<T, T> b) { if (a.second != b.second) { return a.second < b.second; } return a.first < b.first; }
template<class T> T mod_pow(T x, T n, const T& p) { T ret = 1; while (n > 0) { if (n & 1) { (ret *= x) %= p; } (x *= x) %= p; n >>= 1; } return ret; }
template<class T> T math_gcd(T a, T b) { if (b == 0) { return a; } else { return math_gcd(b, a % b); } }

template<class T> void _debug_coutVec(vector<T> ar, string space = " ") { rep(i, ar.size()) { debug(ar[i] << space); } debugln(""); }

constexpr ll MOD = 1000000007;	// 10e9+7

/*****/

void Main()
{
	ll N, K;
	cin >> N >> K;
	vec<ll> A(N);
	rep(i, N)	cin >> A[i];

	ll ret = 0;

	rep(i, N)
	{
		ll all = 0, right = 0;

		rep(j, N)
		{
			if (A[i] > A[j])
			{
				all++;

				if (i < j)	right++;
			}
		}

		if (right >= MOD)	right %= MOD;
		if (all >= MOD)		all %= MOD;

		ret += all * ((K * (K - 1) / 2) % MOD);

		if (ret >= MOD)	ret %= MOD;

		ret += right * K;

		if (ret >= MOD)	ret %= MOD;
	}

	cout << ret;
}

/*****/

int main()
{
	std::ios::sync_with_stdio(false);
	std::cin.tie(0);

	//std::cout << std::fixed << std::setprecision(10);

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
