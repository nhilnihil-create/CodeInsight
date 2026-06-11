#include<bits/stdc++.h>
using namespace std;
int main()
{
	int h,n;
	cin>>h>>n;
	vector<pair<int,int> > arr(n);
	for(int i=0;i<n;i++)
	{
		int a,b;
		cin>>a>>b;
		arr[i]=make_pair(a,b);
	}
	vector<int> dp(10002,INT_MAX);
	dp[0]=0;
	for(int i=0;i<10002;i++)
	{
		for(int j=0;j<n;j++)
		{
			dp[i]=min(dp[i],(dp[max(i-arr[j].first,0)]+arr[j].second));
		}
	}
	cout<<dp[h]<<endl;
	
}