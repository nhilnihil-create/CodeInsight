#pragma region
#define _USE_MATH_DEFINES
#include <iostream>
#include <string>
#include <algorithm>
#include <cmath>
#include <cstdlib>
#include <vector>
#include <map>
#include <queue>
#include <stack>
#include <set>
#include <list>
#include <iomanip>
#include <cstdint>
#include <bitset>

using namespace std;
typedef long long ll;
//#define rep(i, s, e) for (int(i) = (s); (i) < (e); ++(i))
#define rep(i, e) for (int(i) = 0; (i) < (e); ++(i))
#define rrep(i, s) for (int(i) = (s) - 1; (i) >= 0; --(i))
#define all(x) x.begin(),x.end()

#pragma region UnionFind
struct UnionFind
{
	vector<int> par;

	UnionFind(int n) : par(n, -1) {}
	void init(int n) { par.assign(n, -1); }

	int root(int x)
	{
		if (par[x] < 0) return x;
		else return par[x] = root(par[x]);
	}

	bool issame(int x, int y)
	{
		return root(x) == root(y);
	}

	bool merge(int x, int y)
	{
		x = root(x); y = root(y);
		if (x == y) return false;
		if (par[x] > par[y]) swap(x, y);
		par[x] += par[y];
		par[y] = x;
		return true;
	}

	int size(int x)
	{
		return -par[root(x)];
	}
};
#pragma endregion
#pragma region GCD
ll gcd(ll a, ll b)
{
	if (b == 0)return a;
	return gcd(b, a%b);
}
#pragma endregion
#pragma region LCM
ll lcm(ll a, ll b)
{
	return a / gcd(a, b) * b;
}
#pragma endregion
#pragma region chmin
template<class T> inline bool chmin(T& a, T b)
{
	if (a > b)
	{
		a = b;
		return true;
	}
	return false;
}
#pragma endregion
#pragma region chmax
template<class T> inline bool chmax(T& a, T b)
{
	if (a < b)
	{
		a = b;
		return true;
	}
	return false;
}
#pragma endregion
#pragma endregion


int main()
{
	int n, k; cin >> n >> k;
	int r, s, p; cin >> r >> s >> p;
	string t; cin >> t;
	vector<vector<int>> dp(n,vector<int>(3));
	rep(i, k)
	{
		if (t[i] == 's')dp[i][0] = r;
		if (t[i] == 'p')dp[i][1] = s;
		if (t[i] == 'r')dp[i][2] = p;
		for (int j = i + k; j < n; j += k)
		{
			rep(x, 3)
			{
				if (x == 0)
				{
					dp[j][0] = max(dp[j - k][1], dp[j - k][2]);
					if (t[j] == 's')dp[j][0] += r;
				}
				else if (x == 1)
				{
					dp[j][1] = max(dp[j - k][0], dp[j - k][2]);
					if (t[j] == 'p')dp[j][1] += s;
				}
				else
				{
					dp[j][2] = max(dp[j - k][0], dp[j - k][1]);
					if (t[j] == 'r')dp[j][2] += p;
				}
			}
		}
	}
	int res = 0;
	for (int i = n - 1; i > n - k - 1; --i)
	{
		res += max({ dp[i][0],dp[i][1],dp[i][2] });
	}
	cout << res << endl;
}