#include <stdio.h>

int main ()
{
	long long int n;
	scanf("%lld", &n);
	
	long long int sum = 0;
	
	for(int i=0; i<=n; i++)
	{
	
		if(i%3==0 || i%5==0) // fizz
		{
			continue;
		} 
		
		else //buzz
		{
			sum = sum + i;
		}
	}	
	
	printf("%lld", sum);
	
	return 0;
}