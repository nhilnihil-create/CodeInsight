//#include "bits/stdc++.h"

#define _USE_MATH_DEFINES
#include<cstdio>
#include <cstring>
#include <cmath>
#include <cstdlib>
#include <deque>
#include <algorithm>
#include <functional>
#include <iostream>
#include <list>
#include <map>
#include <unordered_map>
#include <numeric>
#include <queue>
#include <set>
#include <sstream>
#include <stack>
#include <string>
#include <utility>
#include <vector>
#include <iterator>
#include<iomanip>
#include<complex>

using namespace std;

#define rep(i,a,b) for(int i=(a), i##_len=(b);i<i##_len;i++)
#define rrep(i,a,b) for(int i=(b)-1;i>=(a);i--)
#define all(c) begin(c),end(c)

#define int ll
#define SZ(x) ((int)(x).size())
#define pb push_back
#define mp make_pair

//typedef unsigned long long ull;
typedef long long ll;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;
typedef pair<ll, int> pli;
typedef pair<int, double> pid;
typedef pair<double, int> pdi;
typedef pair<double, double> pdd;
typedef vector< vector<int> > mat;

template<class T> bool chmax(T &a, const T &b) { if (a < b) { a = b; return true; } return false; }
template<class T> bool chmin(T &a, const T &b) { if (b < a) { a = b; return true; } return false; }

const int INF = sizeof(int) == sizeof(long long) ? 0x3f3f3f3f3f3f3f3fLL : 0x3f3f3f3f;
const int MOD = (int)1e9 + 7;

const double EPS = 1e-9;

struct UnionFind
{
	vector<int> parent;
	vector<int> rank;

	UnionFind(int N) :parent(N, 0), rank(N, 0)
	{
		rep(i, 0, N)parent[i] = i;
	}

	int find(int x)
	{
		if (parent[x] == x)return x;
		else return parent[x] = find(parent[x]);
	}

	void unite(int x, int y)
	{
		x = find(x);
		y = find(y);

		if (x == y)return;

		if (rank[x] < rank[y])parent[x] = y;
		else {
			parent[y] = x;
			if (rank[x] == rank[y])rank[x]++;
		}
	}

	bool same(int x, int y)
	{
		return find(x) == find(y);
	}
};

signed main()
{
	cin.tie(0);
	ios::sync_with_stdio(false);
	
	int N, Q;
	cin >> N >> Q;

	UnionFind uf(N + 1);
	int t, u, v;
	rep(i, 0, Q)
	{
		cin >> t >> u >> v;
		if (t == 0)
		{
			uf.unite(u, v);
		}
		else
		{
			cout << (uf.same(u, v) ? 1 : 0) << endl;
		}
	}

	return 0;
}