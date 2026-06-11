//include
//------------------------------------------
#include <vector>
#include <list>
#include <map>
#include <set>
#include <deque>
#include <queue>
#include <stack>
#include <bitset>
#include <algorithm>
#include <functional>
#include <numeric>
#include <utility>

#include <sstream>
#include <iostream>
#include <iomanip>
#include <cstdio>
#include <cmath>
#include <cstdlib>
#include <cctype>
#include <string>
#include <cstring>
#include <ctime>

#include <stdexcept>

using namespace std;

// type alias
using ll = long long;
using ull = unsigned long long;

//conversion
//------------------------------------------
inline int toint(string s) { int v; istringstream sin(s); sin >> v; return v; }
template<class t> inline string tostring(t x) { ostringstream sout; sout << x; return sout.str(); }

//debug
#define DUMP(x)  cerr << #x << " = " << (x) << endl
#define DEBUG(x) cerr << #x << " = " << (x) << " (l" << __line__ << ")" << " " << __file__ << endl

inline ll floor(ll a, ull b)
{
	ll llb = b;
	if (a >= 0)
	{
		return a / llb;
	}
	else
	{
		return - ( (-a + llb - 1) / llb);
	}
}

inline ll ceil(ll a, ull b)
{
	ll llb = b;
	if (a >= 0)
	{
		return (a + llb - 1) / llb;
	}
	else
	{
		return - (-a / llb);
	}
}

inline ll get_lowest_one_bit(ll a)
{
	return a & (-a);
}

inline ll get_highest_one_bit(ll a)
{
	while ((a & (a - 1)) != 0)
	{
		a = a & (a - 1);
	}
	return a;
}

inline bool is_power2(ull a)
{
	if (a == 0)
	{
		return false;
	}
	return !(a & (a - 1));
}

inline ll get_specified_bit(ll a, unsigned bit)
{
	return (a & (1LL << bit)) >> bit;
}

// computational complexity: o(log(max(a, b))) 
inline ull get_gcd(ull a, ull b)
{
	if (b == 0)
	{
		return a;
	}
	return get_gcd(b, a % b);
}

template<class Integer>
inline Integer get_power(Integer base, ull exponential)
{
	Integer result = 1;
	while (exponential >= 1)
	{
		if (exponential & 1)
		{
			result = result * base;
		}
		base = base * base;
		exponential >>= 1;
	}

	return result;
}

int main()
{
	cin.tie(0);
	ios::sync_with_stdio(false);

	ll N;
	cin >> N;
	
	vector<ll> A_counts(N, 0LL);
	ll a;
	for (ll i = 0; i < N; ++i)
	{
		cin >> a;
		--a;
		++A_counts[a];
	}

	vector<ll> ds(N, 0LL);
	for (ll i = 0; i < N; ++i)
	{
		if (A_counts[i] > 0)
		{
			++ds[A_counts[i] - 1];
		}
	}

	ll sum_d = accumulate(ds.begin(), ds.end(), 0LL);
	ll accum_d = 0, accum_kd = 0;
	vector<ll> fs(N);
	for (ll i = 0; i < N; ++i)
	{
		accum_d += ds[i];
		accum_kd += (i + 1) * ds[i];

		fs[i] = (accum_kd + (i + 1) * (sum_d - accum_d)) / (i + 1);
	}

	vector<ll> res(N);
	for (ll i = 0; i < N; ++i)
	{
		auto iter = upper_bound(fs.begin(), fs.end(), i + 1, greater<ll>());
		auto dist = distance(fs.begin(), iter);
		cout << dist << endl;
	}

	return 0;
}
