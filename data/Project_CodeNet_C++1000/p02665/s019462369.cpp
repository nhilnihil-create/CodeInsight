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
#include <fstream>

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
	int n; cin >> n;
	vector<ll> a(n + 1); rep(i, n + 1)cin >> a[i];
	if (n == 0)
	{
		if (a[0] == 1)cout << 1 << endl;
		else cout << -1 << endl;
		return 0;
	}
	if (n != 0 && a[0] != 0)
	{
		cout << -1 << endl;
		return 0;
	}
	if (n == 1)
	{
		if (a[1] == 1)cout << 2 << endl;
		else if (a[1] == 2)cout << 3 << endl;
		else cout << -1 << endl;
		return 0;
	}
	vector<ll> b(n + 1);
	b[0] = 1;
	rep(i, n)
	{
		ll mx = b[i] * 2;
		if (mx < 0)b[i + 1] = 1e18;
		else b[i + 1] = mx - a[i + 1];
		if (b[i + 1] < 0)
		{
			cout << -1 << endl;
			return 0;
		}
	}
	vector<ll> v(n + 1);
	ll res = a[n] + 1;
	v[n] = a[n];
	for (int i = n; i >= 2; --i)
	{
		if (b[i - 2] >= 1e18)v[i - 1] = v[i] + a[i - 1];
		else v[i - 1] = min(v[i] + a[i - 1], b[i - 2] * 2);
		res += v[i - 1];
	}
	cout << res << endl;
}