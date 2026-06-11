#include <cstdio>
#define MOD 1000000007
using namespace std;

typedef long long LL;

LL pow(LL a, LL n)
{
	LL res = 1;
	while(n > 0)
	{
		if(n & 1)
			res = res * a % MOD;
		a = a * a % MOD;
		n >>= 1;
	}
	return res;
}

LL C(LL n, LL m)
{
	if(n < m) return 0;
	if(m > n - m) m = n - m;
	LL s1 = 1, s2 = 1;
	for(int i=0; i<m; i++)
	{
		s1 = s1 * (n - i) % MOD;
		s2 = s2 * (i + 1) % MOD;
	}
	return s1 * pow(s2, MOD - 2) % MOD;
}

int main(int argc, char** argv)
{
	LL x, y;
	scanf("%lld%lld", &x, &y);
	if((x + y) % 3 != 0)
	{
		puts("0");
		return 0;
	}
	LL sum = (x + y) / 3, diff = x - y;
	LL n = (sum - diff) / 2;
	LL m = n + diff;
	if(n < 0 || m < 0)
	{
		puts("0");
		return 0;
	}
	printf("%lld\n", C(sum, n));
	return 0; 
}