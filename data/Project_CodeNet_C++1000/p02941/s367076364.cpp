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

//conversion
//------------------------------------------
inline int toint(string s) { int v; istringstream sin(s); sin >> v; return v; }
template<class t> inline string tostring(t x) { ostringstream sout; sout << x; return sout.str(); }

//debug
#define dump(x)  cerr << #x << " = " << (x) << endl
#define debug(x) cerr << #x << " = " << (x) << " (l" << __line__ << ")" << " " << __file__ << endl

// type alias
using ll = long long;
using ull = unsigned long long;

// constant value
const ll mod = 1000000007ll;

template<class ll>
inline ll getCeilExponent(ll a)
{
	if (a <= 0)
	{
		throw invalid_argument("vaule equal to or less than 0 should not be valid");
	}

	ll index = 0;
	--a;
	for (; a != 0; a >>= 1)
	{
		++index;
	}
	return index;
}

template<class ll>
inline ll getFloorExponent(ll a)
{
	if (a <= 0)
	{
		throw invalid_argument("vaule equal to or less than 0 should not be valid");
	}

	ll index = 0;
	a >>= 1;
	for (; a != 0; a >>= 1)
	{
		++index;
	}
	return index;
}

// computational complexity: o(log(max(a, b))) 
template<class ll>
inline ll getGcd(ll a, ll b)
{
	if (b == 0)
	{
		return a;
	}
	return getGcd(b, a % b);
}

// computational complexity: o(log(max(a, b))) 
template<class ll>
inline pair<ll, ll> getBezoutsIdentitySolution(ll a, ll b)
{
	if (b == 0)
	{
		return { 1, 0 };
	}
	auto sol = getBezoutsIdentitySolution(b, a % b);
	return { sol.second, sol.first - (a / b) * sol.second };
}

inline ll getModValue(ll a, ll m)
{
	return (a % m + m) % m;
}

// computational complexity: o(log(max(a, n))) 
inline ll getModInverse(ll a, ll m)
{
	auto sol = getBezoutsIdentitySolution(a, m);
	if (a * sol.first + m * sol.second != 1)
	{
		return -1;
	}
	return getModValue(sol.first, m);
}

ll getModPower(ll base, unsigned t, ll m)
{
	if (t == 0)
	{
		return 1ll;
	}

	auto res = getModPower(base, t >> 1, m);
	res = getModValue(res * res, m);
	if (t % 2 == 1)
	{
		res = getModValue(res * base, m);
	}
	return res;
}

class ModCombCalculator
{
private:
	ll n_;
	ll mod_;
	vector<ll> values_;
public:
	ModCombCalculator(ll n, ll mod) : n_(n), values_(n + 1LL, -1LL), mod_(mod)
	{
		values_[0] = 1LL;
	}
	
	ll calculate(ll r)
	{
		if (r < 0LL || n_ < r)
		{
			return 0LL;
		}

		if (values_[r] != -1)
		{
			return values_[r];
		}

		ll res;
		if (values_[r - 1] != -1)
		{
			res = values_[r - 1];
		}
		else
		{
			res = calculate(r - 1);
		}

		values_[r] = getModValue(
			getModValue(res * (n_ - r + 1LL), mod_) * getModInverse(r, mod_),
		mod_);

		return values_[r];
	}
};

int main()
{
	cin.tie(0);
	ios::sync_with_stdio(false);

	ll N;
	cin >> N;

	vector<ll> As(N);
	vector<ll> Bs(N);

	for (ll i = 0; i < N; ++i)
	{
		cin >> As[i];
	}
	
	for (ll i = 0; i < N; ++i)
	{
		cin >> Bs[i];
	}

	//priority_queue<pair<ll, ll>> check;
	set<ll> check;
	for (ll i = 0; i < N; ++i)
	{
		if (Bs[i] > Bs[(i + 1) % N] + Bs[(i != 0) ? (i - 1) : (N - 1)])
		{
			check.insert(i);
		}
	}

	ll res = 0;
	ll pos;
	while (!check.empty())
	{
		ll pos = *(check.begin());

		ll decr = Bs[(pos + 1) % N] + Bs[(pos != 0) ? (pos - 1) : (N - 1)];
		ll quot = (Bs[pos] - As[pos]) / decr ;
		res += quot;
		Bs[pos] -= decr * quot;

		if (Bs[pos] < As[pos])
		{
			res = -1;
			break;
		}

		check.erase(pos);
		ll mpos = (pos != 0) ? (pos - 1) : (N - 1);
		if (Bs[mpos] > Bs[(mpos + 1) % N] + Bs[(mpos != 0) ? (mpos - 1) : (N - 1)])
		{
			check.insert(mpos);
		}
		ll ppos = (pos + 1) % N;
		if (Bs[ppos] > Bs[(ppos + 1) % N] + Bs[(ppos != 0) ? (ppos - 1) : (N - 1)])
		{
			check.insert(ppos);
		}
	}

	for (ll i = 0; i < N; ++i)
	{
		if (Bs[i] != As[i])
		{
			res = -1;
			break;
		}
	}

	cout << res << endl;

	return 0;
}