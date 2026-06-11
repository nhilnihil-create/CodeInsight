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
	/***** 素因数分解ライブラリ *****/

	/**
	@brief 素因数分解をする
	@note
	 nを素因数分解する。計算量O(√n)
	 例えば 18 = 2 * 3 * 3 なので res[2] = 1, res[3] = 2 を返す。
	**/
	void NT_PrimeFactorization(long long n, std::map<long long, long long>& res)
	{
		for (long long i = 2; i * i <= n; i++)
		{
			while (n % i == 0) res[i]++, n /= i;
		}
		if (n != 1) res[n]++;
	}

	/**
	@brief 因数を得る
	@note
	 nの因数xを得る。計算量O(log N)
	 例えば nを素因数分解したときx²の因数をもつとき2を返す。
	**/
	long long NT_PrimeFactorization(long long n, long long x)
	{
		long long res = 0;
		while (n % x == 0)
		{
			res++;
			n /= x;
		}
		return res;
	}
}

namespace NyaGadget
{
	namespace Cpp17
	{
		/**
		@brief 最大公約数を計算する関数
		@note
		 aとbの最大公約数を返す
		**/
		ll Gcd(ll a, ll b)
		{
			return b ? Gcd(b, a % b) : a;
		}

		/**
		@brief 最小公倍数を計算する関数
		@note
		 aとbの最小公倍数を返す
		**/
		ll Lcm(ll a, ll b)
		{
			return a / Gcd(a, b) * b;
		}
	}
};

/**************************************/
/*********** END OF NYA LIB ***********/
/**************************************/

auto CeilD = [] // long double ceiling div
(auto a, auto b) { return (ll)ceil((ld)a / (ld)b); };

using namespace NyaGadget;
//using mll = NT_ModLL< 1000000007 >;
//using mll = NT_ModLL< 998244353 >;

int main(void)
{
	ll N, M; cin >> N >> M;
	vt<ll> a(N); each(i, e, a) cin >> e;

	ll test = NT_PrimeFactorization(a[0], 2);
	each(i, e, a)
	{
		if (NT_PrimeFactorization(e, 2) != test) output(0);
	}

	ll lcm = 1;
	each(i, e, a) e /= 2;
	each(i, e, a) lcm = Cpp17::Lcm(lcm, e);

	cout << CeilD(M / lcm, 2);
	return 0;
}