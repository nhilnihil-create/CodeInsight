#include<stdio.h>

int main()
{
	long long int h,sum=0,n, i, num[100000];
	scanf("%lld%lld", &h, &n);
	
	for(i = 1; i<=n; i++)
	{
		scanf("%lld", &num[i]);
		sum+=num[i];
	}
	if(sum>= h)
		printf("Yes\n");
	else 
		printf("No\n");
		
	return 0;
}