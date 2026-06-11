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
#include <random>
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
#define REPE(i, n) for (int (i)=0; (i) <= (n); (i)++)
#define CONTAINS_MAP(m, a) (m).find((a)) != m.end()
#define CONTAINS_SET(m, a) (m).find((a)) != m.end()
void YesNo(bool b) { cout << (b ? "Yes" : "No") << endl; }
void YESNO(bool b) { cout << (b ? "YES" : "NO") << endl; }

int N, M;
int S[2001];
int T[2001];

int dp[2001][2001];



//---------- 1000000007 ----------
const int MOD = 1000000007;
int m_add(int a, int b)
{
	return (a + b) % MOD;
}
int m_sub(int a, int b)
{
	return (a + MOD - b) % MOD;
}
int m_mul(int a, int b)
{
	return (a * b) % MOD;
}
int m_pow(int x, int n)
{
	if (n == 0) return 1;
	ll res = m_pow((x * x) % MOD, n / 2);
	if (n & 1) res = (res * x) % MOD;
	return res;
}
int m_div(int a, int b)
{
	return m_mul(a, m_pow(b, MOD - 2));
}
int m_comb(int n, int r)
{
	int i;
	int p = 1;
	for (i = 1; i <= r; i++)
	{
		p = m_mul(p, (n - i + 1));
		p = m_div(p, i);
	}
	return p;
}
int m_comb_with_rep(int n, int r)
{
	return m_comb(n + r - 1, r);
}
int m_perm(int n, int r)
{
	int a = 1;
	for (int i = n; i > n - r; i--)
	{
		a = m_mul(a, i);
	}
	return a;
}




signed main()
{
	cin >> N >> M;
	REP(i, N) cin >> S[i];
	REP(i, M) cin >> T[i];

	for (int m = 0; m < M; m++)
	{
		if (S[0] == T[m]) dp[0][m] = 1;
	}

	for (int n = 1; n < N; n++)
	{
		int sum = 0;
		for (int m = 0; m < M; m++)
		{
			if (S[n] == T[m])
			{
				dp[n][m] = m_add(dp[n][m], (sum + 1));
			}
			dp[n][m] = m_add(dp[n][m], dp[n - 1][m]);

			sum = m_add(sum, dp[n - 1][m]);
		}
	}

	int ans = 0;
	for (int m = 0; m < M; m++)
	{
		ans = m_add(ans, dp[N - 1][m]);
	}
	cout << (ans + 1) << endl;
}

