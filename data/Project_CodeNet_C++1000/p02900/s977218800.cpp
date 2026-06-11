#pragma GCC diagnostic ignored "-Wunused-variable" 
#include <bits/stdc++.h>
using namespace std;

#define BOOST
#ifdef BOOST
#include <boost/multiprecision/cpp_int.hpp>
#include <boost/multiprecision/cpp_dec_float.hpp>
#include <boost/range/adaptor/reversed.hpp>
using namespace boost;
using ml = boost::multiprecision::cpp_int;
using md = boost::multiprecision::cpp_dec_float_100;
#define forir(i, ...) if(ll i=(ll)v.size())for(__VA_ARGS__)if(i--,1)
#define eachr(i, e, c) forir(i, auto &&e: adaptors::reverse(c))
#endif

/***** type *****/
using ll = long long;
using ld = long double;
using pll = pair<long long, long long>;
template <class T> using vt = vector<T>;
template <class T> using vvt = vector<vector<T>>;
template <class T> using vvvt = vector<vector<vector<T>>>;
/***** define *****/
#define all(c) (c).begin(), (c).end()            // begin to end
#define coutd cout << fixed << setprecision(10)  // cout double
#define output(x) do{cout<<x;return 0;}while(0)  // cout return
#define rep(i, b, e) for (ll i = b; i < e; i++)  // repeat
#define repr(i, b, e) for (ll i = b; e < i; i--) // repeat reverse
#define fori(i, ...) if (ll i = -1) for(__VA_ARGS__) if (i++, 1)
#define each(i, e, c) fori (i, auto&& e: c)      // for each
/***** const value *****/
#define llong_max 9223372036854775807            // 9 * 10^18
#define ldbl_max 1.79769e+308                    // 1.7 * 10^308
#define pi 3.1415926535897932                    // 3.14 ...
/***** lambda *****/
auto Ceil = [] // if (a % b != 0) return a / b + 1;
(auto x) { return (ll)ceil(x); };
auto Count = [] // long long count value
(auto b, auto e, auto x) { return (ll)count(b, e, x); };
auto CtoL = [] // char to number
(auto c) { return (ll)c - (ll)'0'; };
auto LtoC = [] // number to char
(auto n) { return (char)('0' + n); };
auto Pow = [] // long long pow
(auto a, auto b) { return (ll)pow(a, b); };
auto Pow2 = [] // long long pow2
(auto n) { return (1LL << n); };
auto Pow10 = [] // long long pow10
(auto n) { return (ll)pow(10, n); };
auto Size = []  // long long collection size
(auto& c) { return (ll)(c).size(); };
auto Sum = [] // long long accumulate
(auto b, auto e) { return accumulate(b, e, 0LL); };

/***** template *****/
template <class T> void MakeVVT
(ll ys, ll xs, vvt<T>& v, T fill = T())
{	// vector<vector<T>> resize + fill
	v.resize(ys); rep(y, 0, ys) v[y].resize(xs, fill);
}
template <class T> void MakeVVVT
(ll zs, ll ys, ll xs, vvvt<T>& v, T fill = T())
{	// vector<vector<vector<T>>> resize + fill
	v.resize(zs); rep(z, 0, zs) MakeVVT(ys, xs, v[z], fill);
}
template <class T> void InputVT
(ll xs, vt<T>& v, T fix = T())
{	// input vector<T> (T != struct) + fix
	v.resize(xs); rep(i, 0, xs) { cin >> v[i]; v[i] += fix; }
}
template <class T> void InputVVT
(ll ys, ll xs, vvt<T>& v, T fix = T())
{	// input vector<vector<T>> (T != struct) + fix
	MakeVVT(ys, xs, v, fix);
	rep(y, 0, ys) rep(x, 0, xs) { cin >> v[y][x]; v[y][x] += fix; }
}
template <class T> void InputVVVT
(ll zs, ll ys, ll xs, vvvt<T>& v, T fix = T())
{	// input vector<vector<vector<T>>> (T != struct) + fix
	v.resize(zs); rep(z, 0, zs) InputVVT(ys, xs, v[z], fix);
}

/**************************************/
/********** BEGIN OF NYA LIB **********/
/**************************************/

namespace NyaGadget {}

namespace NyaGadget
{
	/***** 約数列挙ライブラリ *****/

	/**
	@brief 約数を列挙する
	@param
	 nの約数をansに全て格納する。
	 計算量O(sqrt(N))、約数の個数はlog(N)程度になる。
	**/
	void NT_DivisorTable(long long n, std::vector<long long>& ans)
	{
		for (auto i = 1LL; i * i <= n; i++)
		{
			if (n % i == 0)
			{
				ans.push_back(i);
				if (i * i == n) continue;
				ans.push_back(n / i);
			}
		}
		sort(ans.begin(), ans.end());
	}
}

namespace NyaGadget
{	
	/***** 素数テーブルライブラリ *****/

	void PrimeTable(long long n, std::vector<long long>& res)
	{
		std::vector<bool> test(n + 1, true);
		test[0] = test[1] = false;
		for (auto i = 2LL; i * i <= n; i++)
		{
			if (!test[i]) continue;
			for (long long j = 2 * i; j <= n; j += i) test[j] = false;
		}

		res.clear();
		for (auto i = 0LL; i < (long long)test.size(); i++)
		{
			if (test[i]) res.push_back(i);
		}
	}

	void PrimeTable(long long n, std::vector<bool>& res)
	{
		res.resize(n+1, true);
		res[0] = res[1] = false;
		for (auto i = 2LL; i * i <= n; i++)
		{
			if (!res[i]) continue;
			for (long long j = 2 * i; j <= n; j += i) res[j] = false;
		}
	}
}

namespace NyaGadget
{
	/***** 素数判定ライブラリ *****/

	/**
	@brief 素数かどうか調べる
	@note
	xが素数のときtrueを返し、そうでないときfalseを返す。
	なお、xが1のときは素数でないのでfalseを返す。
	**/
	bool NT_IsPrime(long long x)
	{
		if (x == 1) return false;
		for (auto i = 2LL; i * i <= x; ++i)
		{
			if (x % i == 0) return false;
		}
		return true;
	}
}

/**************************************/
/*********** END OF NYA LIB ***********/
/**************************************/

using namespace NyaGadget;
//using mll = NT_ModLL< 1000000007 >;
//using mll = NT_ModLL< 998244353 >;

int main(void)
{
	ll A, B; cin >> A >> B;
	std::vector<long long> ares, bres;
	NT_DivisorTable(A, ares);
	NT_DivisorTable(B, bres);

	map<ll, ll> count;
	each(i, e, ares) count[e]++;
	each(i, e, bres) count[e]++;

	ll ans = 0;
	std::vector<bool> prime;
	PrimeTable(Pow10(6) + 1, prime);
	each(i, e, count)
	{
		if (e.second == 2 && NT_IsPrime(e.first)) ans++;
	}
	cout << ans + 1;
	return 0;
}
