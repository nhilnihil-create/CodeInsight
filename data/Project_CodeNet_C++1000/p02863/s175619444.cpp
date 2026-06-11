#include<bits/stdc++.h>
using namespace std;
int n , t;
int f[3005][3005],g[3005][3005];
int a[3005],b[3005];
int main()
{
	scanf("%d%d",&n,&t);
	--t;
	for(int i=1;i<=n;++i)
	    scanf("%d%d",&a[i],&b[i]);
	int INF=-1e9;
	for(int i=1;i<=n;++i)
		for(int j=0;j<=t;++j)
		   f[i][j]=max(j>=a[i]?f[i-1][j-a[i]]+b[i]:INF,f[i-1][j]);
	for(int i=n;i>=1;--i)
		for(int j=0;j<=t;++j)
		   g[i][j]=max(j>=a[i]?g[i+1][j-a[i]]+b[i]:INF,g[i+1][j]);
	int ans=0;
    for(int i=1;i<=n;++i)
    	for(int j=0;j<=t;++j)
    		ans=max(ans,f[i-1][j]+g[i+1][t-j]+b[i]);
    cout<<ans<<endl;
	return 0;
}