#include<bits/stdc++.h>
#define int long long
using namespace std;
int n,k,g[200001][65]; 
signed main()
{
	scanf("%lld %lld",&n,&k);
	for(int i=1;i<=n;i++)
		scanf("%lld",&g[i][0]);
	for(int l=1;l<=63;l++)
		for(int i=1;i<=n;i++)
			g[i][l]=g[g[i][l-1]][l-1];
	int now=1,cnt=0;
	while(k)
	{
		if(k&1)
			now=g[now][cnt];
		cnt++;
		k/=2;
	}
	cout<<now;
	return 0;
}