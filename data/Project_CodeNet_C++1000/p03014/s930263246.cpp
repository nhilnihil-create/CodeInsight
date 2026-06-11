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
int gcd(int a, int b)
{
	if (a%b == 0)return b;
	return gcd(b, a%b);
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
	int h, w; cin >> h >> w;
	vector<string> s(h); rep(i, h)cin >> s[i];
	vector<vector<int>> l(h, vector<int>(w)), r(h, vector<int>(w)), u(h, vector<int>(w)), d(h, vector<int>(w));
	rep(i, h)rep(j, w)
	{
		int cnt = 0;
		while (j < w&&s[i][j] == '.')
		{
			++cnt;
			l[i][j] = cnt;
			++j;
		}
		if (j == w)continue;
		if (s[i][j] == '#')l[i][j] = 0;
	}
	rep(i, h)rep(j, w)
	{
		int cnt = 0;
		while (j < w&&s[i][w - j - 1] == '.')
		{
			++cnt;
			r[i][w - j - 1] = cnt;
			++j;
		}
		if (j == w)continue;
		if (s[i][w - j - 1] == '#')r[i][w - j - 1] = 0;
	}
	rep(i, w)rep(j, h)
	{
		int cnt = 0;
		while (j < h&&s[j][i] == '.')
		{
			++cnt;
			u[j][i] = cnt;
			++j;
		}
		if (j == h)continue;
		if (s[j][i] == '#')u[j][i] = 0;
	}
	rep(i, w)rep(j, h)
	{
		int cnt = 0;
		while (j < h&&s[h - j - 1][i] == '.')
		{
			++cnt;
			d[h - j - 1][i] = cnt;
			++j;
		}
		if (j == h)continue;
		if (s[h - j - 1][i] == '#')d[h - j - 1][i] = 0;
	}
	int res = 0;
	rep(i, h)rep(j, w)
	{
		chmax(res, l[i][j] + r[i][j] + u[i][j] + d[i][j] - 3);
	}
	cout << res << endl;
}