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
int m_divide(int a, int b)
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
		p = m_divide(p, i);
	}
	return p;
}

int m_comb_with_rep(int n, int r)
{
	return m_comb(n + r - 1, r);
}



//---------- 最大公約数 ----------
int gcd(int x, int y)
{
	int r;
	while ((r = x % y) != 0)
	{
		x = y;
		y = r;
	}
	return y;
}


int N, K;
int temp[100010];

signed main()
{
	cin >> N >> K;

	int ans = 0;

	for (int i = K; i >= 1; i--)
	{
		int cnt = 0;

		int a = K / i;
		int aa = m_pow(a, N);
		cnt = m_add(cnt, aa);
		
		for (int j = i + i; j <= K; j += i)
		{
			cnt = m_sub(cnt, temp[j]);
		}

		temp[i] = cnt;

		int b = m_mul(cnt, i);
		ans = m_add(ans, b);
	}

	cout << ans << endl;
}


