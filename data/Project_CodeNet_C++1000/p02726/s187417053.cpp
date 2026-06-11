#include<bits/stdc++.h>
using namespace std;

int n,x,y;
int dis[2010][2010];
int cnt[2010];

int main()
{
	scanf("%d%d%d",&n,&x,&y);
	for(int i=1;i<=n;i++) for(int j=i+1;j<=n;j++)
	{
		dis[i][j]=min(j-i,min(abs(i-x)+abs(j-y)+1,abs(i-y)+abs(j-x)+1));
		cnt[dis[i][j]]++;
	}
	for(int i=1;i<n;i++) printf("%d\n",cnt[i]);
	return 0;
}