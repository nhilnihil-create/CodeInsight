#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int maxn=3e3+5;
int N,T;
int dp1[maxn][maxn],dp2[maxn][maxn];
int a[maxn],b[maxn];
int main()
{
	cin>>N>>T;
	for(int i=1;i<=N;i++)
	{
		cin>>a[i]>>b[i];
	}
	for(int i=1;i<=N;i++)
	{
		for(int j=0;j<=T;j++)
		dp1[i][j]=dp1[i-1][j];
		for(int j=a[i];j<=T;j++)
		dp1[i][j]=max(dp1[i][j],dp1[i-1][j-a[i]]+b[i]);
	}
	for(int i=N;i>=1;i--)
	{
		for(int j=0;j<=T;j++)
		dp2[i][j]=dp2[i+1][j];
		for(int j=a[i];j<=T;j++)
		dp2[i][j]=max(dp2[i][j],dp2[i+1][j-a[i]]+b[i]);	
	}	
	int ans=0;
	for(int i=1;i<=N;i++)
	{
		for(int j=0;j<T;j++)
		ans=max(ans,dp1[i-1][j]+dp2[i+1][T-1-j]+b[i]);
	}
	cout<<ans;
}