#include <bits/stdc++.h>

#define F first
#define S second

using namespace std;

typedef long long LL;
typedef pair<int, int> PII;

const int N = 110, M = 110, mod = 1e9 + 7;

int n, a, b;

int qp(int a, int b)
{
	int res = 1;
	while (b)
	{
		if (b & 1) res = (LL)res * a % mod;
		a = (LL)a * a % mod;
		b >>= 1;
	}
	return res;
}

int C(int a, int b)
{
	int res = 1;
	for (int i = a; i > a - b; i -- ) res = (LL)res * i % mod;
	for (int i = 1; i <= b; i ++ ) res = (LL)res * qp(i, mod - 2) % mod;
	return res;
}

int main()
{
	cin >> n >> a >> b;
	int res = qp(2, n) - C(n, a) - C(n, b) - 1;
	res = (res % mod + mod) % mod;
	cout << res << endl;
	return 0;
}