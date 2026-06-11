#include <bits/stdc++.h>
#define MAX 10000007
using namespace std;
 
int main()
{
	
	long int i,j,count=0,x;
	vector<long int> prime;
	prime.assign(MAX, 1);
	

	prime[0] = prime[1] = false;
	
	for(i=2;i<MAX;i++)
	{
		if(prime[i] == false);
		else{
			for(j=2*i;j<MAX;j+=i)
			{
				prime[j] = false;
			}
		}
	}
	
	scanf("%ld", &x);
	
	while(1)
	{
		if(prime[x] == 1)
		{
			printf("%ld",x);
			return 0;
		}
		else x++;
	}
}