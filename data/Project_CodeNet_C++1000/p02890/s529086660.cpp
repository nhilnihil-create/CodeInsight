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
#include<unordered_set>
#include<bitset>

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
int A[300010];
int D[300010];
pii F[300010];

signed main()
{
	cin.tie(0);
	ios::sync_with_stdio(false);

	cin >> N;
	rep(i, 0, N)
	{
		cin >> A[i];
	}

	sort(A, A + N);

	int DN = 0;
	int c = 0;
	int pa = A[0];
	rep(i, 0, N)
	{
		if (A[i] != pa)
		{
			D[DN] = c;
			c = 0;
			DN++;
		}
		c++;
		pa = A[i];
		if (i == N - 1)
		{
			D[DN] = c;
			c = 0;
			DN++;
		}
	}

	sort(D, D + DN);

	int r = 0;
	int t = 0;
	rep(i, 1, N + 1)
	{
		while (r < DN&&D[r] < i)r++;
		t += DN - r;
		F[i - 1] = mp(t / i, i);
	}

	sort(F, F + N, [&](const pii& a, const pii& b) {return a.first != b.first ? a.first<b.first : a.second>b.second; });

	rep(i, 1, N + 1)
	{
		auto itr = lower_bound(F, F + N, mp(i, 0LL));
		if (itr == F + N)
		{
			cout << 0 << endl;
		}
		else
		{
			cout << itr->second << endl;;
		}
	}

	return 0;
}