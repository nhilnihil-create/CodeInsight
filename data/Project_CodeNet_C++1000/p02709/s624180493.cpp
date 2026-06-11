#include<iostream>
#include<algorithm>
#define ll long long
using namespace std;
const int N=2e3+5;
ll dp[N][N];
struct node
{
	int x,id;
};
node a[N];
int cmp(node a,node b)
{
	return a.x>b.x;
}
int main()
{
	int n;
	cin>>n;
	for(int i=1;i<=n;i++)
	{
		cin>>a[i].x;
		a[i].id=i;
	}
	sort(a+1,a+n+1,cmp);
	for(int k=1;k<=n;k++)
	{
		for(int i=0;i<k;i++)
		{
			int j=k-i-1;
			dp[i+1][j]=max(dp[i+1][j],dp[i][j]+(ll)a[k].x*(a[k].id-(i+1)));
			dp[i][j+1]=max(dp[i][j+1],dp[i][j]+(ll)a[k].x*(n-j-a[k].id));
		}
	}
	ll ans=0;
	for(int i=0;i<=n;i++)
		ans=max(ans,dp[i][n-i]);
	cout<<ans;
	return 0; 
} 