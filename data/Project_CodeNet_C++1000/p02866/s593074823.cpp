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
//const int MOD = (int)1e9 + 7;
const int MOD = 998244353;

const double EPS = 1e-9;

int modpow(int x, int n, const int mo) {
	int res = 1;
	while (n > 0) {
		if (n & 1) (res *= x) %= mo;
		(x *= x) %= mo;
		n >>= 1;
	}
	return res;
}

signed main()
{
	cin.tie(0);
	ios::sync_with_stdio(false);

	int N;
	cin >> N;
	vector<int> CNT(N, 0);

	int A;
	bool ok = true;
	rep(i, 0, N)
	{
		cin >> A;
		if (i == 0 && A != 0)ok = false;
		CNT[A]++;
	}

	if (!ok||CNT[0] != 1)
	{
		cout << 0 << endl;
		return 0;
	}

	int sum = 0;
	int ans = 1;
	rep(i, 0, N)
	{
		if (i>0&&sum < N)
		{
			ans *= modpow(CNT[i - 1], CNT[i], MOD);
			ans %= MOD;
		}
		sum += CNT[i];
	}

	cout << ans << endl;

	return 0;
}
