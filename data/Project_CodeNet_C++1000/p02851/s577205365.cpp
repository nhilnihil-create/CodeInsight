#pragma warning (disable:4996)
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
#define eachr(i, e, c) forir(i, const auto &e: adaptors::reverse(c))
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
#define rep(i, b, e) for (ll i = b; i < e; i++)  // repeat
#define repr(i, b, e) for (ll i = b; e < i; i--) // repeat reverse
#define fori(i, ...) if (ll i = -1) for(__VA_ARGS__) if (i++, 1)
#define each(i, e, c) fori (i, auto& e: c)       // for each
/***** const value *****/
#define llong_max 9223372036854775807            // 9 * 10^18
#define ldbl_max 1.79769e+308                    // 1.7 * 10^308
#define pi 3.1415926535897932                    // 3.14 ...
#define loop_end 9223372036854775806             // LLONG_MAX-1
/***** lambda *****/
auto Count = [] // long long count value
(auto b, auto e, auto x) { return (ll)count(b, e, x); };
auto CtoL = [] // char to number
(auto c) { return (ll)c - (ll)'0'; };
auto DivCeil = [] // if (a % b != 0) return a / b + 1;
(auto a, auto b) { return (ll)ceil((ld)a / (ld)b); };
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

/**************************************/
/*********** END OF NYA LIB ***********/
/**************************************/

using namespace NyaGadget;
//using mll = ModLL< 1000000007 >;
//using mll = ModLL< 998244353 >;

int main(void)
{
	ll N, K; cin >> N >> K;
	vt<ll> A; InputVT(N, A);

	vt<ll> sum; sum.push_back(0);
	each(i, e, A) sum.push_back((sum.back() + e) % K);

	ll ans = 0;
	queue<ll> range;
	map<ll, ll> countSMI; // sum - index
	rep(i, 0, Size(sum))
	{
		//ll nyaa = abs(sum[i] - i) % K;
		ll nyaa = (sum[i] - i) % K;
		if (nyaa < 0) nyaa += K;
		ans += countSMI[nyaa]++;
		range.push(nyaa);
		if (K <= Size(range))
		{
			countSMI[range.front()]--;
			range.pop(); // FIFO
		}
	}

	cout << ans;
	return 0;
}
