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
	int n, k, c; cin >> n >> k >> c;
	string s; cin >> s;
	vector<int> p(n + 1), l(n + 1), q(n + 1), r(n + 1);
	p[0] = -1e9;
	q[n] = 1e9;
	rep(i, n)
	{
		if (s[i] == 'o'&&p[i] + c < i)
		{
			p[i + 1] = i;
			l[i + 1] = l[i] + 1;
		}
		else
		{
			p[i + 1] = p[i];
			l[i + 1] = l[i];
		}
	}
	rrep(i, n)
	{
		if (s[i] == 'o'&&q[i + 1] - c > i)
		{
			q[i] = i;
			r[i] = r[i + 1] + 1;
		}
		else
		{
			q[i] = q[i + 1];
			r[i] = r[i + 1];
		}
	}
	vector<int> res;
	rep(i, n)
	{
		int tmp = l[i];
		int x = max(i + 1, p[i] + c + 1);
		if (x <= n)tmp += r[x];
		if (tmp < k)res.push_back(i + 1);
	}
	for (int x : res)cout << x << endl;
}