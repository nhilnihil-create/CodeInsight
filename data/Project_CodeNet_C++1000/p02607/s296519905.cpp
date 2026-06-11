#include<iostream>
#include<cstring>
#include<cstdio>
#include<cmath>
#include<vector>
#include<map>
#include<algorithm>
#include<queue>
using namespace std;
int n,m,ans;
int main()
{
	//freopen("a.in","r",stdin);
	//freopen("a.out","w",stdout);
	scanf("%d",&n);
	for (int i=1;i<=n;i++)
	{
		scanf("%d",&m);
		if (i&1 && m&1) ans++;	
	} 
	printf("%d",ans);
	return 0;
}