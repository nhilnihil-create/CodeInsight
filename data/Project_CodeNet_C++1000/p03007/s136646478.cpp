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
	vector<int> P, Z, N;
	rep(i, n)
	{
		int a; cin >> a;
		if (a > 0)P.push_back(a);
		else if (a == 0)Z.push_back(a);
		else N.push_back(a);
	}
	int Pnum = P.size(), Znum = Z.size(), Nnum = N.size();
	if (Znum != 0)
	{
		int s = 0;
		for (int x : P)s += x;
		for (int x : N)s -= x;
		cout << s << endl;
		int now = 0;
		rep(i, Pnum - 1)
		{
			cout << now << " " << P[i] << endl;
			now -= P[i];
		}
		if (Pnum != 0)
		{
			cout << P.back() << " " << now << endl;
			now = P.back() - now;
		}
		rep(i, Nnum)
		{
			cout << now << " " << N[i] << endl;
			now -= N[i];
		}
		rep(i, Znum - 1)cout << now << " " << 0 << endl;
	}
	else if (Pnum == 0)
	{
		sort(all(N));
		int s = 0;
		for (int x : N)s -= x;
		s += N.back() * 2;
		cout << s << endl;
		int now = N.back();
		rep(i, Nnum - 1)
		{
			cout << now << " " << N[i] << endl;
			now -= N[i];
		}
	}
	else if (Nnum == 0)
	{
		sort(all(P));
		int s = 0;
		for (int x : P)s += x;
		s -= P[0] * 2;
		cout << s << endl;
		int now = P[0];
		for (int i = 1; i <= Pnum - 2; ++i)
		{
			cout << now << " " << P[i] << endl;
			now -= P[i];
		}
		cout << P.back() << " " << now << endl;
	}
	else
	{
		int s = 0;
		for (int x : P)s += x;
		for (int x : N)s -= x;
		cout << s << endl;
		int now = N[0];
		rep(i, Pnum - 1)
		{
			cout << now << " " << P[i] << endl;
			now -= P[i];
		}
		cout << P.back() << " " << now << endl;
		now = P.back() - now;
		for (int i = 1; i < Nnum; ++i)
		{
			cout << now << " " << N[i] << endl;
			now -= N[i];
		}
	}
}