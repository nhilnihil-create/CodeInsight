#include <bits/stdc++.h>
using namespace std;
long long n,k,a[200005],dp[200005][100];
int main()
{
	cin>>n>>k;
	for(int i=1;i<=n;i++)
		cin>>a[i];
	for(int i=1;i<=n;i++)
		dp[i][0]=a[i];
	for(int i=0;i<=70;i++)
	{
		for(int j=1;j<=n;j++)
			dp[j][i+1]=dp[dp[j][i]][i];
	}
	long long p=k,t=0,res=1;
	while(p)
	{
		if(p%2)
			res=dp[res][t];
		t++;
		p/=2;
	}
	cout<<res;

	return 0; 
}