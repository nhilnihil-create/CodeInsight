#include<cstdio>
typedef long long LL;
LL a[5], ans = ( 1e18 + 5 ) * (-1);
LL max(LL a, LL b)
{
	return a > b ? a : b;
}
int main()
{
	for(int i = 1; i <= 4; i ++)
		scanf("%lld", &a[i]);
	for(int i = 1; i <= 2; i ++)
		for(int j = 3; j <= 4; j ++)
			ans = max(a[i] * a[j], ans);
	printf("%lld", ans);
}