#include<bits/stdc++.h>
using namespace std;
int n,b[105];
int ans;
int main()
{
	scanf("%d",&n);
	for(int i=1;i<=n-1;++i)
	    scanf("%d",&b[i]);
	for(int i=2;i<=n-1;++i)
	    ans+=min(b[i-1],b[i]);
	ans+=b[1]+b[n-1];
	printf("%d\n",ans);
	return 0;
}