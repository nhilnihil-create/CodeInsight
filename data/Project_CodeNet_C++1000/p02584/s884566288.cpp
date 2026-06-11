#include <bits/stdc++.h>
using namespace std;

int main()
{
	long long int X, K, D;
	scanf("%lld%lld%lld", &X, &K, &D);
	
	if(X == 0)
	{
		if(K % 2 == 1)
			printf("%lld", D);
			
		else
			printf("0");
			
		return 0;
	}
	
	long long mod = abs(X) % D;
	if(X < 0)
		mod = mod * (-1);
	
	long long numSteps = abs(X - mod) / D;
	if(numSteps >= K)
	{
		if(X < 0)
			printf("%lld", abs(X + K * D) );
			
		else
			printf("%lld", abs(X - K * D) );
	}
	
	else if((K - numSteps) % 2 == 0)
		printf("%lld", abs(mod) );
		
	else
	{
		if(X < 0)
			printf("%lld", abs(mod + D));
			
		else
			printf("%lld", abs(mod - D));
	}
}