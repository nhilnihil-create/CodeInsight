#include <bits/stdc++.h>

#define F first
#define S second

using namespace std;

typedef long long LL;
typedef pair<int, int> PII;

const int N = 100010, M = 1010, mod = 1e9 + 7;

int x, y;

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
	cin >> x >> y;
	
	int s = x + y;
	if (s % 3 == 0 && min(x, y) >= s / 3)
	{
		int c = s / 3;
		if (c == 0) puts("1");
		else cout << C(c, x % c) << endl;
	}
	else puts("0");
	return 0;
}