#include <bits/stdc++.h>
using namespace std;

int main()
{
	long long K;
	scanf("%lld", &K);
	
	long long rem = 7 % K;
	for(int i = 1; i <= 1000000; i++)
	{
		if(rem == 0)
		{
			printf("%d", i);
			return 0;
		}
		
		rem = (rem * 10) % K;
		rem = (rem + 7) % K;
	}
	
	printf("-1");
}
