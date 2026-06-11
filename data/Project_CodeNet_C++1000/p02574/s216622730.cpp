#include<iostream>
#include<cstring>
#include<cstdio>
#include<cmath>
using namespace std;
const int SIZE = 1000000 + 5;
int n, m, A, a[SIZE], e[SIZE], v[SIZE], prime[SIZE];
int GCD(int x, int y)
{
	return y ? GCD(y, x % y) : x;
}
void primes()
{
	memset(v, 0, sizeof(v));
	m = A = 0;
	for(int i = 0; i < n; ++ i) A = max(A, a[i]);
	for(int i = 2; i <= A; ++ i)
	{
		if(!v[i])
		{
			v[i] = i;
			prime[++ m] = i;
		}
		for(int j = 1; j <= m; ++ j)
		{
			if(prime[j] > v[i] || prime[j] > A / i) break;
			v[prime[j] * i] = prime[j];
		}
	}
	return;
}
void divide()
{
	memset(e, -1, sizeof(e));
	for(int i = 0; i < n; ++ i)
	{
		int t;
		while(v[a[i]])
		{
			t = v[a[i]];
			a[i] /= t;
			if(e[t] == -1) e[t] = i;
			else if(e[t] != i) 
			{
				puts("setwise coprime");
				return;
			}
		}
	}
	puts("pairwise coprime");
	return;
}
int main()
{
	scanf("%d", &n);
	for(int i = 0; i < n; ++ i) scanf("%d", &a[i]);
	primes();
	int tmp = a[0];
	for(int i = 1; i < n; ++ i) tmp = GCD(tmp, a[i]);
	if(tmp > 1)
	{
		puts("not coprime");
		return 0;
	}
	divide();
	return 0;
}