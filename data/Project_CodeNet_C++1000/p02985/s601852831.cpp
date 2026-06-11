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
#define CONTAINS_MAP(m, a) (m).find((a)) != m.end()
#define CONTAINS_SET(m, a) (m).find((a)) != m.end()
void YesNo(bool b) { cout << (b ? "Yes" : "No") << endl; }
void YESNO(bool b) { cout << (b ? "YES" : "NO") << endl; }



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

int N, K;
vector<int> _link[100001];
int _ans = 1;


void func(int depth, int parent, int n)
{
	int a = K - min(2LL, depth);
	int r = 0;
	for (int l : _link[n])
	{
		if (l != parent)
		{
			r++;
			func(depth + 1, n, l);
		}
	}

	if (r == 0)
	{
		return;
	}

	int p = m_perm(a, r);
	_ans = m_mul(_ans, p);
}

signed main()
{
	cin >> N >> K;
	REP(i, N - 1)
	{
		int a, b;
		cin >> a >> b;
		_link[a].push_back(b);
		_link[b].push_back(a);
	}

	func(1, -1, 1);
	cout << m_mul(_ans, K) << endl;
}

