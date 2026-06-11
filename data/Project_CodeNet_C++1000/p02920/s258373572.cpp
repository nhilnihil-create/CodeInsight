#include <bits/stdc++.h>
#include <boost/multiprecision/cpp_int.hpp>

/***** type *****/
using namespace std;
using ll = long long;
using ld = long double;
template <class T> using vt = vector<T>;
template <class T> using vvt = vector<vector<T>>;
template <class T> using vvvt = vector<vector<vector<T>>>;
template <class T1, class T2> using umap = unordered_map<T1, T2>;
using ml = boost::multiprecision::cpp_int;

/***** define *****/
#define all(c) (c).begin(), (c).end()            // begin to end
#define rep(i, b, e) for (ll i = b; i < e; i++)  // repeat
#define repr(i, b, e) for (ll i = b; e < i; i--) // repeat reverse
#define val(itr) *(itr)                          // get value
/***** const value *****/
#define llong_max 9223372036854775807            // 9 * 10^18
#define ldbl_max 1.79769e+308                    // 1.7 * 10^308
#define pi 3.1415926535897932                    // 3.14 ...
/***** for each macro *****/
#define fori(i, ...) if(ll i = -1) for(__VA_ARGS__) if(i++, true)
#define each(i, e, c) fori(i, auto e = c.begin(); e != c.end(); ++e)
#define forir(i, v, ...) if(ll i=(ll)v.size())for(__VA_ARGS__)if(i--,true)
#define eachr(i, e, c) forir(i, auto e = c.rbegin(); e != c.rend(); ++e)

/***** lambda *****/
auto Count = [] // long long count value
(auto b, auto e, auto x) { return (ll)count(b, e, x); };
auto CtoN = [] // char to number
(auto c) { return (ll)(c - '0'); };
auto DivC = [] // long double div ceiling
(auto a, auto b) { return ceil((ld)a / (ld)b); };
auto Fix = [] // fix value
(auto b, auto e, auto fix)
{ for (auto it = b; it != e; ++it)*it += fix; };
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
template <class T> vvt<T> VVT
(ll ys, ll xs, T fill = T())
{	// vector<vector<T>> resize + fill
	vvt<T> v(ys);
	each(i, y, v) { y->resize(xs, fill); } return v;
}
template <class T> vvvt<T> VVVT
(ll zs, ll ys, ll xs, T fill = T())
{	// vector<vector<vector<T>>> resize + fill
	vvvt<T> v(zs);
	each(i, z, v) { val(z) = VVT(ys, xs, fill); } return v;
}
template <class T> vt<T> InputVT
(ll size, T fix = T())
{	// input vector<T> (T != struct) + fix
	vt<T> v(size);
	rep(i, 0, size) { cin >> v[i]; v[i] += fix; }
	return v;
}
template <class T> vvt<T> InputVVT
(ll ys, ll xs, T fix = T())
{	// input vector<vector<T>> (T != struct) + fix
	vvt<T> v(ys); each(i, y, v) y->resize(xs);
	rep(y, 0, ys) rep(x, 0, xs) { cin >> v[y][x]; v[y][x] += fix; }
	return v;
}
template <class T> vvvt<T> InputVVVT
(ll zs, ll ys, ll xs, T fix = T())
{	// input vector<vector<vector<T>>> (T != struct) + fix
	vvvt<T> v(zs);
	each(i, z, v) { val(z) = InputVVT<T>(ys, xs, fix); }
	return v;
}

//using namespace NyaGadget;
//using mll = ModLL<1000000007>;

int main(void)
{
	ll N; cin >> N;
	vt<ll> v = InputVT<ll>(Pow2(N));
	sort(all(v), greater<ll>());
	multiset<ll> mset;
	each(i, e, v) mset.insert(val(e));

	vt<ll> test;
	test.push_back(v[0]);
	mset.erase(mset.find(v[0]));
	rep(i, 0, N)
	{
		sort(all(test), greater<ll>());
		rep(j, 0, Pow2(i))
		{
			auto it = mset.lower_bound(test[j]);
			if (it == mset.begin())
			{	// 同値はNG
				cout << "No";
				return 0;
			}
			it--;
			test.push_back(*it);
			mset.erase(it);
		}
	}

	cout << "Yes";
	return 0;
}

