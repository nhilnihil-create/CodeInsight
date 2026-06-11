#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int maxn=2e5+50;
int t,n,m;
int arr[maxn];
struct node
{
	ll x;int id;
}poi[2050];
bool comp(node a,node b)
{
	if(a.x!=b.x) return a.x>b.x;
	return a.id>b.id;
}
ll dp[2050][2050];
int main()
{
	ios::sync_with_stdio(false);
	cin>>n;
	for(int i=1;i<=n;i++)
	{
		cin>>poi[i].x;
		poi[i].id=i;
	}
	sort(poi+1,poi+1+n,comp);
	for(int i=1;i<=n;i++)
	{
		for(int j=0;j<=i;j++)
		{
			ll id=poi[i].id;
			ll x=poi[i].x;
			if(i-1>=j) dp[i][j]=max(dp[i][j],dp[i-1][j]+abs(id-(n-i+1+j))*x);
			if(j>0) dp[i][j]=max(dp[i][j],dp[i-1][j-1]+abs(id-j)*x);
		}
	}
	ll fin=0;
	for(int i=0;i<=n;i++)
	{
		fin=max(fin,dp[n][i]);
	}
	cout<<fin<<endl;
	return 0;
}