#include <bits/stdc++.h>
using namespace std;
#define N 1000005
int n,m,ans[N];
int main()
{
	scanf("%d %d",&n,&m);
	if(n&1) for(int i=1;i<=m;++i) printf("%d %d\n",i,n-i);
	else
	{
		for(int i=1;i<=((n>>1)>>1);++i) ans[i]=n-i+1;
		for(int i=((n>>1)>>1)+1;i<=(n>>1);++i) ans[i]=n-i;
		for(int i=1;i<=m;++i) printf("%d %d\n",i,ans[i]);
	}return 0;
}