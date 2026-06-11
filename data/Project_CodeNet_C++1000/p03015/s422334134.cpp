#include <stdio.h>
#include <string.h>
#define mod 1000000007
int M(long long a, long long b, long long c)//a ^ b mod c
{
	int ans = 1;
	a = a % c;
	while (b != 0)
	{
		if (b & 1)
			ans = ans * a % c;
		a = a * a % c;
		b = b >> 1;
	}
	return ans;
}
char a[100005];
int main()
{
	int l,i,len;
	long long sum = 1,sum2=0;
	scanf("%s", a);
	len = strlen(a);
	for (i = 0; i < len; i++)
	{
		if (a[i] == '1')
		{
			sum2 = (sum2 + sum * M(3, len - i - 1, mod)) % mod;
			sum *= 2;
			sum %= mod;
		}
	}
	printf("%lld", (sum + sum2) % mod);
}