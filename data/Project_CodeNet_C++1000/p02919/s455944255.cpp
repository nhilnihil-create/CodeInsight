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

int N;
int P[100010];

signed main()
{
	cin.tie(0);
	ios::sync_with_stdio(false);

	cin >> N;
	int p;
	rep(i, 1, N + 1)
	{
		cin >> p;
		P[p] = i;
	}

	multiset<int> lset;
	multiset<int> rset;
	lset.insert(0);
	rset.insert(N + 1);

	int ans = 0;

	rrep(i, 1, N + 1)
	{
		int ll, lr, rl, rr;
		lr = -(*lset.upper_bound(-P[i]));
		if (lr == 0)ll = 0;
		else
			ll = -(*lset.upper_bound(-lr));
		rl = *rset.upper_bound(P[i]);
		if (rl == N + 1)rr = N + 1;
		else
			rr = *rset.upper_bound(rl);

		ans += i*((lr - ll)*(rl - P[i]) + (P[i] - lr)*(rr - rl));

		rset.insert(P[i]);
		lset.insert(-P[i]);
	}

	cout << ans << endl;

	return 0;
}