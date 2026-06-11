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

int N, M;
int S[2010], T[2010];
int dp[2010][2010];
int sum[2010][2010];

signed main()
{
	cin.tie(0);
	ios::sync_with_stdio(false);

	cin >> N >> M;
	rep(i, 0, N)
	{
		cin >> S[i];
	}
	rep(i, 0, M)
	{
		cin >> T[i];
	}

	rep(i, 0, N)
	{
		rep(j, 0, M)
		{
			if (S[i] == T[j])
			{
				dp[i + 1][j + 1] = sum[i][j] + 1;
				dp[i + 1][j + 1] %= MOD;
			}
			sum[i + 1][j + 1] = sum[i][j + 1] + sum[i + 1][j]+ MOD - sum[i][j] + dp[i + 1][j + 1];
			sum[i + 1][j + 1] %= MOD;
		}
	}

	cout << (sum[N][M] + 1) % MOD << endl;

	return 0;
}