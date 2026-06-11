#include <stdio.h>

int main ()
{
	int n;
	scanf("%d", &n);
	
	long long int A1[n];
	long long int A2=1;
	long long int max=1000000000000000000;
	
	for(int i=0; i<n; i++)
	{
		scanf("%lld", &A1[i]);
	}
	
	for(int j=0; j<n; j++)
	{
		if(A1[j]==0)
		{
			printf("0\n");
			return 0;
		}	
	}	
	
	for(int k=0; k<n; k++)
	{
		if(A1[k] <= max/A2)
		{
			A2 *= A1[k];	
		}
		
		else 
		{
			printf("-1\n");
			return 0;
		}
	}	
	
	printf("%lld\n", A2);
	
	return 0;
}