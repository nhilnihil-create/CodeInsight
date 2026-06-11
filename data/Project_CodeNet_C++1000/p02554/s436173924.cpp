#include <cstdio>
#include <iostream>
using namespace  std;
const long long mod = 1e9 + 7;
typedef long long LL;
int n;
LL Pow(LL a, LL b)
{
	LL sum = 1;
	while(b)
	{
		if(b & 1) sum = (sum * a)% mod;
		a = (a * a) % mod;
		b >>= 1;
	}
/*	for(int i = 1; i <= b; i ++)
	 sum = (sum * a) % mod;*/
	return sum;
}
int main()
{
	scanf("%d", &n);
	if(n < 2)
	{
		printf("0");
		return 0;
	}
	LL a = Pow(10, n), b = 2 * Pow(9, n), c = Pow(8, n);
	LL ans = ( a - b + c + mod * mod ) % mod;
	printf("%lld", ans);
	return 0;
}
/*
4 206;
3 4;
_ _ _ _ _ 0
_ _ _ _ _ 0 
*/