#define _USE_MATH_DEFINES
#define _CRT_SECURE_NO_WARNINGS

#include <iostream>
#include <string>
#include <sstream>
#include <iomanip>
#include <cmath>
#include <cstring>
#include <cstdlib>
#include <algorithm>
#include <stack>
#include <queue>
#include <vector>
#include <list>
#include <set>
#include <map>
#include <bitset>
#include <utility>
#include <numeric>
#include <iterator>

using namespace std;

using ll = long long;
using ull = unsigned long long;

const ll inf = 1ll << 60;
const ll mod = (ll)1e9 + 7;

#define all(v) v.begin(), v.end()
#define rall(v) v.rbegin(), v.rend()

#define print(s) cout << s;
#define println(s) cout << s << endl;
#define printd(s, f) cout << fixed << setprecision(f) << s << endl;


int main()
{
	string s;
	cin >> s;

	ll n = s.length();

	if (n == 1)
	{
		println(1);
	}
	else if (n == 2)
	{
		if (s[0] == s[1])
		{
			println(1);
		}
		else
		{
			println(2);
		}
	}

	vector<ll> dp(n);

	dp[0] = 1;
	if (s[0] == s[1])
	{
		dp[1] = 1;
	}
	else
	{
		dp[1] = 2;
	}

	if (s[0] != s[1] && s[1] != s[2])
	{
		dp[2] = 3;
	}
	else
	{
		dp[2] = 2;
	}

	for (ll i = 3; i < n; i++)
	{
		if (s[i - 1] == s[i])
		{
			dp[i] = dp[i - 3] + 2;
		}
		else
		{
			dp[i] = dp[i - 1] + 1;
		}
	}

	println(dp[n - 1]);
}