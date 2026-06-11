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

ll dfs(ll currNode, const vector<set<ll>>& edges, vector<ll>& lengths, vector<bool>& haveChecked)
{
	if (lengths[currNode] != -1)
	{
		return lengths[currNode];
	}

	haveChecked[currNode] = true;
	ll length = 0;
	for (auto& node : edges[currNode])
	{
		if (haveChecked[node])
		{
			continue;
		}
		length = max(length, dfs(node, edges, lengths, haveChecked) + 1);
	}
	lengths[currNode] = length;

	return length;
}

int main()
{
	cin.tie(0);
	ios::sync_with_stdio(false);

	ll N;
	cin >> N;

	if (isPower2(N))
	{
		cout << "No" << endl;
		return 0;
	}

	cout << "Yes" << endl;
	cout << 1 << " " << 2 << endl;
	cout << 2 << " " << 3 << endl;
	cout << 3 << " " << N + 1 << endl;
	cout << N + 1 << " " << N + 2 << endl;
	cout << N + 2 << " " << N + 3 << endl;

	for (ll i = 4; i + 1 <= N; i += 2)
	{
		cout << i << " " << i + 1 << endl;
		cout << i + 1 << " " << 1 << endl;
		cout << N + 1 << " " << i + N << endl;
		cout << i + N << " " << i + N + 1 << endl;
	}

	if (N % 2 == 0)
	{
		auto pow2 = getHighestOneBit(N);
		cout << N << " " << pow2 + N << endl;
		cout << (pow2 ^ N ^ 1) << " " << N * 2 << endl;
	}

	return 0;
}
