#include<cstdio>
#include<iostream>
#include<algorithm>
using namespace std;
int main()
{
	long long int dp[101][21] = {0};
	int  n, s[101],i,j;
	scanf("%d", &n);
	for (i = 1; i <= n; i++)
		scanf("%d", &s[i]);
	dp[1][s[1]] = 1;
	for ( i = 1; i <= n-1; i++)
	{
		for (j = 0; j <21; j++)
		{
			if (dp[i][j] >=1)
			{
				if(j+s[i+1]<=20)
					dp[i + 1][j + s[i+1]] +=dp[i][j] ;
				if(j-s[i+1]>=0)
					dp[i + 1][ j- s[i+1]] += dp[i][j];
			}
		}
	}
	printf("%lld\n", dp[n - 1][s[n]]);
	return 0;
}