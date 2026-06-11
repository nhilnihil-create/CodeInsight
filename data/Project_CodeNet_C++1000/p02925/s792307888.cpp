
#include<iostream>
#include<algorithm>
#include<cstdio>
#include<cstring>
#include<string>
#include<cmath>
#include<vector>
#include<map>
#include<set>
#include<queue>
#include<stack>
using namespace std;
typedef long long ll;
const int INF=0x3f3f3f3f,maxn=1e3+50;
int a[maxn][maxn],nowp[maxn],vis[maxn],n;
int main()
{
	int i,j,k,ans=0;
	cin>>n;
	for(i=1;i<=n;i++)
	{
		nowp[i]=1;
		for(j=1;j<=n-1;j++)
			cin>>a[i][j];
	}
	int cnt=1;
	while(1)
	{
		bool f=false;
		for(i=1;i<=n;i++)
		{
			if(nowp[i]>=n || vis[i]==cnt)
				continue;
   			j=a[i][nowp[i]];
			if(vis[j]!=cnt && nowp[j]<n && a[j][nowp[j]]==i)
			{
				nowp[j]++;
				nowp[i]++;
				vis[i]=vis[j]=cnt;
				f=true;
			}
		}
		if(!f)
			break;
		cnt++;
	}
	for(int i=1;i<=n;i++)
	{
		if(nowp[i]!=n)
		{
			cout<<-1;
			return 0;
		}
	}
	cout<<cnt-1;
	return 0;
}