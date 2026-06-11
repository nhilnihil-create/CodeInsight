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

//Z-algorithm
vector<int> Zalgo(const string &S)
{
	int N = (int)S.size();
	vector<int> res(N);
	res[0] = N;
	int i = 1, j = 0;
	while (i < N)
	{
		while (i + j < N && S[j] == S[i + j]) ++j;
		res[i] = j;
		if (j == 0) { ++i; continue; }
		int k = 1;
		while (i + k < N && k + res[k] < j) res[i + k] = res[k], ++k;
		i += k, j -= k;
	}
	return res;
}


int main()
{
	int n; cin >> n;
	string s; cin >> s;
	int res = 0;
	rep(i, n - 1)
	{
		string tmp = s.substr(i);
		vector<int> Z = Zalgo(tmp);
		rep(j, Z.size())
		{
			res = max(res, min(j, Z[j]));
		}
	}
	cout << res << endl;
}