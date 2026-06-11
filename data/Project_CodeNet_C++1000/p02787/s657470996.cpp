#include<bits/stdc++.h>
using namespace std;
int H,N;
int a[1005],b[1005];
int f[1005][20005];
int main()
{
	scanf("%d%d",&H,&N);
	for(int i=1;i<=N;++i) 
	    scanf("%d%d",&a[i],&b[i]);
	for(int i=0;i<=N;++i)
	   for(int j=0;j<=20005;++j)
	       f[i][j]=1e9;
	f[0][0]=0;
	int INF=1e9;
	for(int i=1;i<=N;++i)
	{
		for(int j=0;j<=20000;++j)
		   f[i][j] = min (j>=a[i] ? f[i][j-a[i]]+b[i] : INF, f[i-1][j] ); 
	}
	int ans=1e9;
	for(int i=H;i<=20000;++i)
		ans=min(ans,f[N][i]);
	cout<<ans<<endl;
	return 0;
}