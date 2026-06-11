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
typedef pair<int, double> pid;
typedef pair<double, double> pdd;
typedef vector< vector<int> > mat;

template<class T> bool chmax(T &a, const T &b) { if (a < b) { a = b; return true; } return false; }
template<class T> bool chmin(T &a, const T &b) { if (b < a) { a = b; return true; } return false; }

const int INF = sizeof(int) == sizeof(long long) ? 0x3f3f3f3f3f3f3f3fLL : 0x3f3f3f3f;
const int MOD = (int)1e9 + 7;
const double EPS = 1e-9;

int dp[310][310];

signed main()
{
	cin.tie(0);
	ios::sync_with_stdio(false);

	int N, K;
	int H[310];

	cin >> N >> K;
	rep(i, 1, N+1)
	{
		cin >> H[i];
	}
	H[0] = 0;
	N++;

	rep(i, 0, 310)rep(j, 0, 310)dp[i][j] = INF;
	dp[0][1] = 0;

	//rep(i, 1, N)rep(j, 0, i)rep(k, max(0LL, j - K), j + 1)
	rep(i, 1, N)rep(j, 0, i)rep(k, 1, j + 2)
	{
		chmin(dp[i][k + 1], dp[j][k] + max(0LL, H[i] - H[j]));
	}

	int ans = INF;
	if (K >= N-1)ans = 0;
	else
	{
		rep(i, 0, N)
		{
			chmin(ans, dp[i][N - K]);
		}
	}

	cout << ans << endl;

	return 0;
}