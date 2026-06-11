#define _USE_MATH_DEFINES
#include <iostream>
#include <sstream>
#include <string>
#include <list>
#include <vector>
#include <queue>
#include <algorithm>
#include <climits>
#include <cstring>
#include <cmath>
#include <stack>
#include <iomanip>
#include <tuple>
#include <functional>
#include <cfloat>
#include <map>
#include <set>
#include <array>
#include <stdio.h>
#include <string.h>
#include <random>
using ll = long long;
using ull = unsigned long long;
using namespace std;
#define int long long
#define CONTAINS_VEC(v,n) (find((v).begin(), (v).end(), (n)) != (v).end())
#define SORT(v) sort((v).begin(), (v).end())
#define RSORT(v) sort((v).rbegin(), (v).rend())
#define ARY_SORT(a, size) sort((a), (a)+(size))
#define REMOVE(v,a) (v.erase(remove((v).begin(), (v).end(), (a)), (v).end()))
#define REVERSE(v) (reverse((v).begin(), (v).end()))
#define ARY_REVERSE(v,a) (reverse((v), (v)+(a)))
#define REP(i, n) for (int (i)=0; (i) < (n); (i)++)
#define REPE(i, n) for (int (i)=0; (i) <= (n); (i)++)
#define CONTAINS_MAP(m, a) ((m).find((a)) != m.end())
#define CONTAINS_SET(m, a) ((m).find((a)) != m.end())
void YesNo(bool b) { cout << (b ? "Yes" : "No") << endl; }
void Yes() { cout << "Yes" << endl; }
void No() { cout << "No" << endl; }


struct UnionFind {
	vector<int> d;
	UnionFind(int n = 0) : d(n, -1) {}
	int find(int x) {
		if (d[x] < 0) return x;
		return d[x] = find(d[x]);
	}
	bool unite(int x, int y) {
		x = find(x); y = find(y);
		if (x == y) return false;
		if (d[x] > d[y]) swap(x, y);
		d[x] += d[y];
		d[y] = x;
		return true;
	}
	bool same(int x, int y) { return find(x) == find(y); }
	int size(int x) { return -d[find(x)]; }
};


signed main()
{
	int N, M;
	cin >> N >> M;

	UnionFind uf(N);

	REP(i, M)
	{
		int a, b;
		cin >> a >> b;
		a--;b--;
		uf.unite(a, b);
	}

	int ans = 0;
	REP(i, N)
	{
		ans = max(ans, uf.size(i));
	}
	cout << ans << endl;
}

