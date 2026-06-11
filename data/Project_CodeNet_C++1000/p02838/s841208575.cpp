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
#include <set>
#include <array>
#include <stdio.h>
#include <string.h>
using ll = long long;
using ull = unsigned long long;
using namespace std;
#define int long long
#define CONTAINS(v,n) (find((v).begin(), (v).end(), (n)) != (v).end())
#define SORT(v) sort((v).begin(), (v).end())
#define RSORT(v) sort((v).rbegin(), (v).rend())
#define ARY_SORT(a, size) sort((a), (a)+(size))
#define REMOVE(v,a) (v.erase(remove((v).begin(), (v).end(), (a)), (v).end()))
#define REVERSE(v) (reverse((v).begin(), (v).end()))
#define ARY_REVERSE(v,a) (reverse((v), (v)+(a)))
#define REP(i, n) for (int (i)=0; (i) < (n); (i)++)
#define CONTAINS_MAP(m, a) (m).find((a)) != m.end()
void YesNo(bool b) { cout << (b ? "Yes" : "No") << endl; }
void YESNO(bool b) { cout << (b ? "YES" : "NO") << endl; }
//max_element



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



int N;
int A[300010];

signed main()
{
	cin >> N;
	REP(i, N) cin >> A[i];

	int ans = 0;
	for (int i = 0; i < 60; i++)
	{
		int n0 = 0;
		int n1 = 0;
		for (int j = 0; j < N; j++)
		{
			if ((A[j] & (1LL << i)) == 0)
				n0++;
			else
				n1++;
		}
		int s = m_mul(n0, n1);
		int b = (1LL << i) % MOD;
		int a = m_mul(b, s);
		ans = m_add(ans, a);
	}
	cout << ans << endl;
}

