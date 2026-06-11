#include <stdio.h>
int a[2000005], b[2000005], flag[2000005] = { 0 };
int main()
{
	int n, i, j, mod;
	long long k;
	scanf("%d %lld", &n, &k);
	for (i = 1; i <= n; i++)
		scanf("%d", &a[i]);//a[i]存下一位
	flag[1] = 0;
	b[1] = a[1];
	i = 1;
	j = 1;
	while (flag[b[j]]==0&&j<=k)
	{
		flag[b[j]] = j;
		b[j+1] = a[b[j]];
		j++;
	}
//	b[j]已经有了
	if (j > k)
	{
		printf("%d", b[k]);
		return 0;
	}
	mod = j - flag[b[j]];
	k = k - flag[b[j]];
	k = k % mod;
	k = k + flag[b[j]];
	printf("%d", b[k]);
}