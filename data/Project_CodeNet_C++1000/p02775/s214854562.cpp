#define _USE_MATH_DEFINES
#include <iostream>
#include <sstream>
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
#include <set>
#include <array>
#include <stdio.h>
#include <string.h>
using ll = long long;
using ull = unsigned long long;
using namespace std;
#define int long long
#define CONTAINS_VEC(v,n) (find((v).begin(), (v).end(), (n)) != (v).end())
#define SORT(v) sort((v).begin(), (v).end())
#define RSORT(v) sort((v).rbegin(), (v).rend())
#define ARY_SORT(a, size) sort((a), (a)+(size))
#define REMOVE(v,a) (v.erase(remove((v).begin(), (v).end(), (a)), (v).end()))
#define REVERSE(v) (reverse((v).begin(), (v).end()))
#define ARY_REVERSE(v,a) (reverse((v), (v)+(a)))
#define REP(i, n) for (int (i)=0; (i) < (n); (i)++)
#define CONTAINS_MAP(m, a) (m).find((a)) != m.end()
#define CONTAINS_SET(m, a) (m).find((a)) != m.end()
void YesNo(bool b) { cout << (b ? "Yes" : "No") << endl; }
void YESNO(bool b) { cout << (b ? "YES" : "NO") << endl; }

int dp[1000001][2];

int func1(string N)
{
	int len = N.length();

	dp[0][1] = 10 - (N[len - 1] - '0');
	dp[0][0] = (N[len - 1] - '0');

	for (int i = 1; i < len; i++)
	{
		char ch = N[len - i - 1];
		int n = ch - '0';

		int a0 = 10 - (n + 1) + dp[i - 1][1];
		int a1 = 10 - n + dp[i - 1][0];
		dp[i][1] = min(a0, a1);

		int b0 = n + 1 + dp[i - 1][1];
		int b1 = n + dp[i - 1][0];
		dp[i][0] = min(b0, b1);
	}

	return min(dp[len - 1][1] + 1, dp[len - 1][0]);
}

int count_func(int n)
{
	int cnt = 0;
	while (n > 0)
	{
		cnt += n % 10;
		n /= 10;
	}
	return cnt;
}

int func2(string s)
{
	int n;
	istringstream iss(s);
	iss >> n;

	int mi = INT_MAX;
	for (int i = n; i < 2000; i++)
	{
		int sub = i - n;
		int n = count_func(i) + count_func(sub);
		mi = min(mi, n);
	}
	return mi;
}

signed main()
{
	string N;
	cin >> N;
	cout << func1(N) << endl;
}

