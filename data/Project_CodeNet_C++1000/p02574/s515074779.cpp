#pragma warning(disable:4996)
#include <stdio.h>
#include <algorithm>
using namespace std;
int d[1001000];
int vis[1001000];
int gcd(int a, int b)
{
	if (!a || !b) return a + b;
	else return a > b ? gcd(a % b, b) : gcd(a, b % a);
}
int a[1001000];
int main()
{
	int n;
	scanf("%d", &n);
	for (int i = 1; i <= n; i++)
	{
		scanf("%d", &a[i]);
	}
	d[1] = 1;
	for (int i = 2; i <= 1000000; i++)
	{
		if (d[i] != 0) continue;
		for (int j = 1; j * i <= 1000000; j++) d[i * j] = i;
	}
	bool pairchk = 0;
	for (int i = 1; i <= n; i++)
	{
		int c = a[i];
		while (d[c] != c)
		{
			int p = d[c];
			if (vis[p])
			{
				pairchk = 1;
				break;
			}
			vis[p] += 1;
			while (c % p == 0) c /= p;
		}
		if (pairchk) break;
		if (c == 1) continue;
		if (vis[c])
		{
			pairchk = 1;
		}
		vis[c] += 1;
	}
	if (!pairchk)
	{
		printf("pairwise coprime");
		return 0;
	}
	int gcd_=a[1];
	for (int i = 1; i <= n; i++)
	{
		gcd_ = gcd(a[i], gcd_);
	}
	if (gcd_ == 1)
	{
		printf("setwise coprime");
		return 0;
	}
	printf("not coprime");
}