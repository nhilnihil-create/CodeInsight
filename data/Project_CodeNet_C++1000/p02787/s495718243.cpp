#include<bits/stdc++.h>
using namespace std;
int main()
{
	int h,n;
	cin>>h>>n;
	int a[n],b[n];
	for(int i=0;i<n;i++)
	cin>>a[i]>>b[i];
	int dp[h+1];
	dp[0]=0;
	for(int i=1;i<=h;i++)
	dp[i]=INT_MAX;
	for(int i=1;i<=h;i++)
	{
		for(int j=0;j<n;j++)
		{
			dp[i]=min(dp[i],dp[max(0,i-a[j])]+b[j]);
		}
	}
	cout<<dp[h];
}