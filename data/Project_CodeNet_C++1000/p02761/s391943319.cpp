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
	int n, m; cin >> n >> m;
	if (n == 1)
	{
		if (m == 0)cout << 0 << endl;
		else
		{
			int s, c; cin >> s >> c;
			int res = c;
			--m;
			rep(i, m)
			{
				int s, c; cin >> s >> c;
				if (res != c)
				{
					cout << -1 << endl;
					return 0;
				}
			}
			cout << res << endl;
		}
		return 0;
	}
	vector<char> res(n);
	rep(i, m)
	{
		int s; cin >> s;
		--s;
		char c; cin >> c;
		if (s == 0 && c == '0')
		{
			cout << -1 << endl;
			return 0;
		}
		if (res[s] == NULL)res[s] = c;
		else if (res[s] != c)
		{
			cout << -1 << endl;
			return 0;
		}
	}
	if (res[0] == NULL)res[0] = '1';
	for (int i = 1; i < n; ++i)if (res[i] == NULL)res[i] = '0';
	rep(i, n)cout << res[i];
}