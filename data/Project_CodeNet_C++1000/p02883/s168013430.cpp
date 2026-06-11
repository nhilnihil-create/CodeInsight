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

int N, K;
int A[200010];
int F[200010];
int D[200010];

signed main()
{
	cin.tie(0);
	ios::sync_with_stdio(false);

	cin >> N >> K;
	rep(i, 0, N)
	{
		cin >> A[i];
	}
	rep(i, 0, N)
	{
		cin >> F[i];
	}

	sort(A, A + N);
	sort(F, F + N, greater<int>());

	rep(i, 0, N)
	{
		D[i] = A[i] * F[i];
	}

	int l = -1, r = 1e13;
	while (r - l > 1)
	{
		int mid = (l + r) / 2;
		int sum = 0;
		rep(i, 0, N)
		{
			if (D[i] > mid)
			{
				sum += (D[i] - mid + F[i] - 1) / F[i];
			}
		}
		if (sum <= K)
		{
			r = mid;
		}
		else
		{
			l = mid;
		}
	}

	cout << r << endl;

	return 0;
}
