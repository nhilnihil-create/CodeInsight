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
#define output(x) do{cout<<x;exit(0);}while(0)   // cout exit
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
	/***** DFSライブラリ *****/

	struct GT_NyaaDFS
	{
		map<ll,ll> q;
		/**
		@brief DFS処理関数
		@param r 頂点vの根
		@param v 現在の頂点
		@param g 隣接リストか隣接行列
		@param res 処理結果
		**/
		void Run(long long r, long long v, const std::vector<std::vector<long long>>& g, std::vector<long long>& res)
		{
			if (r == -1) res[v] = q[v];
			else res[v] = res[r] + q[v];
			for (auto e : g[v])
			{	// 後戻りしないようにする
				if (e == r) continue;
				Run(v, e, g, res);
			}
		}
	};
}

/**************************************/
/*********** END OF NYA LIB ***********/
/**************************************/

using namespace NyaGadget;
//using mll = NT_ModLL< 1000000007 >;
//using mll = NT_ModLL< 998244353 >;

int main(void)
{
	ll N, Q; cin >> N >> Q;

	std::vector<std::vector<long long>> g(N);
	rep(i, 0, N-1)
	{
		ll a, b; cin >> a >> b; --a, --b;
		g[a].push_back(b);
		g[b].push_back(a);
	}

	GT_NyaaDFS dfs;
	rep(i, 0, Q)
	{
		ll p, x; cin >> p >> x; --p;
		dfs.q[p] += x;
	}
	std::vector<long long> res(N);
	dfs.Run(-1, 0, g, res);

	each(i, e, res) cout << e << " ";
	return 0;
}
