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
typedef pair<double, double> pdd;
typedef vector< vector<int> > mat;

template<class T> bool chmax(T &a, const T &b) { if (a < b) { a = b; return true; } return false; }
template<class T> bool chmin(T &a, const T &b) { if (b < a) { a = b; return true; } return false; }

const int INF = sizeof(int) == sizeof(long long) ? 0x3f3f3f3f3f3f3f3fLL : 0x3f3f3f3f;
const int MOD = (int)1e9 + 7;
const double EPS = 1e-9;

struct P
{
	double x, y, r;
	P(double x, double y) :x(x), y(y), r(atan2(y, x) + M_PI) {}
	P() :P(0.0, 0.0) {}
	bool operator<(const P& other)const
	{
		return r < other.r;
	}
};

int N;
vector<P> Ps;
vector<double> ct;

signed main()
{
	cin.tie(0);
	ios::sync_with_stdio(false);

	cin >> N;
	double x, y;
	rep(i, 0, N)
	{
		cin >> x >> y;
		Ps.push_back(P(x, y));
	}

	sort(all(Ps));

	double ans = 0.0;
	rep(i, 0, N)
	{
		pdd res = mp(Ps[i].x, Ps[i].y);
		int j = (i + 1) % N;
		chmax(ans, sqrt(res.first*res.first + res.second*res.second));
		while (j != i)
		{
			res.first += Ps[j].x;
			res.second += Ps[j].y;
			chmax(ans, sqrt(res.first*res.first + res.second*res.second));
			j = (j + 1) % N;
		}

	}

	cout << fixed << setprecision(12) << ans << endl;

	return 0;
}