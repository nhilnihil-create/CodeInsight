#include <stdio.h>
int main()
{
	long int N;
	int tanda=0;
	scanf ("%d",&N);
	long int A [N];
	long long int risolt=1;
	long long int limit=1000000000000000000;
	for (int i=0;i<N;i++)
	{
		scanf ("%lld",&A[i]);
		if (A[i]==0)
		{
			puts ("0");
			return 0;
		}
	}
		for (int i=0;i<N;i++)
	{
		if (A[i]>limit)
		{
			puts ("-1");
			return 0;
		}
		limit=limit/A[i];
		risolt=risolt*A[i];
	}
	printf ("%lld\n",risolt);
	return 0;
	
}