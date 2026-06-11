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

inline ll getLowestOneBit(ll a)
{
	return a & (-a);
}

inline ll getHighestOneBit(ll a)
{
	while ((a & (a - 1)) != 0)
	{
		a = a & (a - 1);
	}
	return a;
}

inline bool isPower2(ull a)
{
	if (a == 0)
	{
		return false;
	}
	return !(a & (a - 1));
}

inline ll getSpecifiedBit(ll a, unsigned bit)
{
	return (a & (1LL << bit)) >> bit;
}

// computational complexity: o(log(max(a, b))) 
inline ull getGcd(ull a, ull b)
{
	if (b == 0)
	{
		return a;
	}
	return getGcd(b, a % b);
}

template<class Integer>
inline Integer getPower(Integer base, ull exponential)
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

	map<ll, ll> S;
	ll s;
	for (ll i = 0; i < 1LL << N; ++i)
	{
		cin >> s;
		if (S.count(s) == 0)
		{
			S[s] = 0;
		}
		++S[s];
	}

	bool can_make = true;

	ll limit = 1;
	ll cum_limit = limit;

	auto cum_iter = S.end();
	ll cum_count = 0;
	for (ll i = 0; i < N; ++i)
	{
		if (cum_iter-- == S.begin())
		{
			can_make = false;
			break;
		}
		cum_count += cum_iter->second;
		if (cum_count > cum_limit)
		{
			can_make = false;
			break;
		}
		limit = limit * (N - i) / (i + 1);
		cum_limit += limit;
	}

	limit = (1LL << N) >> 1;
	cum_limit = limit;

	cum_iter = S.begin();
	cum_count = 0;
	for (ll i = 0; i < N; ++i)
	{
		if (cum_iter == S.end())
		{
			can_make = false;
			break;
		}
		cum_count += cum_iter->second;
		if (cum_count > cum_limit)
		{
			can_make = false;
			break;
		}

		++cum_iter;
		limit >>= 1;
		cum_limit += limit;
	}

	cout << (can_make ? "Yes" : "No") << endl;

	return 0;
}
