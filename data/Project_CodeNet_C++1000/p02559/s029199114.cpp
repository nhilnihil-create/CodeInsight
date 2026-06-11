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

struct BIT //0-indexed
{
	vector<int> node;
	int mn;

	BIT(int mn)
	{
		this->mn = mn;
		node.resize(mn + 1, 0);
	}

	void add(int i, int x)
	{
		i++;
		while (i <= mn)
		{
			node[i] += x;
			i += (i&-i);
		}
	}

	int sum(int i)
	{
		i++;
		int res = 0;
		while (i > 0)
		{
			res += node[i];
			i -= (i&-i);
		}
		return res;
	}

	//k:0-indexed
	int get(long long k) {
		++k;
		int res = 0;
		int N = 1; while (N < (int)node.size()) N *= 2;

		for (int i = N / 2; i > 0; i /= 2) {
			if (res + i < (int)node.size() && node[res + i] < k) {
				k = k - node[res + i];
				res = res + i;
			}
		}
		return res;
	}
};

signed main()
{
	cin.tie(0);
	ios::sync_with_stdio(false);
	
	int N, Q;
	cin >> N >> Q;

	BIT bit(N + 5);

	int t, idx, x;
	rep(i, 0, N)
	{
		cin >> x;
		bit.add(i, x);
	}

	rep(i, 0, Q)
	{
		cin >> t >> idx >> x;
		if (t == 0)
		{
			bit.add(idx, x);
		}
		else
		{
			cout << bit.sum(x-1) - (idx == 0 ? 0LL : bit.sum(idx - 1)) << endl;
		}
	}

	return 0;
}