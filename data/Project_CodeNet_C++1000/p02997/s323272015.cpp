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
	/***** 数え上げライブラリ *****/

	template< typename T > struct NT_Counting
	{	// 引数にModライブラリを渡すことも可能

		static T P(long long n, long long r)
		{
			if (r < 0 || n < r) return 0;

			T res = 1;
			for (long long i = n; n - r < i; i--) res *= i;
			return res;
		}

		static T C(long long n, long long r)
		{
			if (r < 0 || n < r) return 0;

			T res = 1;
			for (long long i = n; n - r < i; i--) res *= i;
			for (long long i = r; 0 < i; i--) res /= i;
			return res;
		}

		static T H(long long n, long long r)
		{
			if (n < 0 || r < 0) return 0;
			return (r == 0) ? 1 : C(n + r - 1, r);
		}

		static T Catalan(long long n)
		{
			return C(2 * n, n) - C(2 * n, n - 1);
		}

		/**
		@brief 累乗の計算
		@note
		 繰り返し自乗法でxのn乗を返す。計算量O(logN)
		**/
		static T Pow(long long x, long long n)
		{
			T res = 1;
			if (0 < n)
			{
				res = Pow(x, n / 2);
				res = res * res;
				if (n % 2 != 0) res *= x;
			}
			return res;
		}
	};
}

/**************************************/
/*********** END OF NYA LIB ***********/
/**************************************/

using namespace NyaGadget;
//using mll = ModLL< 1000000007 >;
//using mll = ModLL< 998244353 >;

int main(void)
{
	ll N, K; cin >> N >> K;
	if (NT_Counting<ll>::C(N - 1, 2) < K) output(-1);

	vt<pair<ll, ll>> ans;
	rep(i, 2, N + 1) ans.push_back({ 1,i });

	ll k = NT_Counting<ll>::C(N - 1, 2);
	[&] {
		rep(i, 2, N) rep(j, i + 1, N + 1)
		{
			if (k == K) return;
			ans.push_back({ i,j });
			k--;
		}
	} ();

	cout << Size(ans) << endl;
	each(i, e, ans) cout << e.first << " " << e.second << endl;
	return 0;
}
