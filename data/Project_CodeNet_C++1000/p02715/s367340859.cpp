#include <bits/stdc++.h>

using namespace std;

const long long int MOD = 1e9 + 7;
long long int mypow(long long int x,long long int n)
{
	long long int res = 1;
	while(n > 0)
	{
		if(n%2==1)
		{
			res = ((res%MOD) * (x%MOD)%MOD);
			res%=MOD;
		}
		x = ((x%MOD)*(x%MOD)%MOD);
		x%=MOD;
		n/=2;
	}
	return res;
}
long long int dp[100001];

int main(void)
{
	cin.tie(0);
	ios::sync_with_stdio(false);

	int n,k;

	cin >> k >> n;

	long long int res = 0;
	
	for(int i=n;i>=1;i--)
	{
		dp[i] = mypow(n/i,k);
		for(int j=2*i;j<=n;j+=i)
		{
			dp[i] -= dp[j];
			if(dp[i] < 0)
			{
				dp[i] += MOD;
			}
		}
		res = ((res%MOD) + ((i%MOD)*(dp[i]%MOD)%MOD)%MOD);
		res%=MOD;
	}

	cout << res << '\n';

	return 0;
}