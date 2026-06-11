#define _USE_MATH_DEFINES
#include <iostream>
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
#include <stdio.h>
#include <string.h>
using ll = long long;
using namespace std;
//LLONG_MAX = 90^18
#define int long long
#define CONTAINS(v,n) (find((v).begin(), (v).end(), (n)) != (v).end())
#define SORT(v) sort((v).begin(), (v).end())
#define RSORT(v) sort((v).rbegin(), (v).rend())
#define ARY_SORT(a, size) sort((a), (a)+(size))
#define REMOVE(v,a) (v.erase(remove((v).begin(), (v).end(), (a)), (v).end()))
#define REVERSE(v) (reverse((v).begin(), (v).end()))
#define LOWER_BOUND(v,a) (lower_bound((v).begin(), (v).end(), (a)))
#define UPPER_BOUND(v,a) (upper_bound((v).begin(), (v).end(), (a)))
#define REP(i, n) for (int (i)=0; (i) < (n); (i)++)
#define CONTAINS_MAP(m, a) (m).find((a)) != m.end()
void YesNo(bool b) { cout << (b ? "Yes" : "No"); }
void Yes() { cout << "Yes"; }
void No() { cout << "No"; }


int _dp[2010][2010];
int N;
int A[2010];

using P = pair<int, int>;
vector<P> p;

int left[2010];
int right[2010];

signed main()
{
	cin >> N;
	REP(i, N)
	{
		cin >> A[i];
		p.push_back(make_pair(A[i], i));
	}

	RSORT(p);

	for (int i = 0; i < N; i++)
	{
		int score = 0;

		for (int j = 0; j <= i; j++)
		{
			int len = abs(j - p[i].second);
			int s = len * p[i].first;

			int prev = _dp[j][i - j];
			int next = prev + s;
			_dp[j + 1][i - j] = max(_dp[j + 1][i - j], next);
		}

		for (int j = 0; j <= i; j++)
		{
			int r = N - 1 - j;

			int len = abs(r - p[i].second);
			int s = len * p[i].first;

			int prev = _dp[i - j][j];
			int next = prev + s;
			_dp[i - j][j + 1] = max(_dp[i - j][j + 1], next);
		}
	}

	int m = 0;
	for (int i = 0; i < N; i++)
	{
		m = max(m, _dp[i][N - i]);
	}

	cout << m << endl;
}


