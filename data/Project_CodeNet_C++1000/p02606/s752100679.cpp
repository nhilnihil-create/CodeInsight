#include<iostream>
#include<cstring>
#include<cstdio>
#include<cmath>
#include<vector>
#include<map>
#include<algorithm>
#include<queue>
using namespace std;
int l,r,d,ans;
int main()
{
	//freopen("a.in","r",stdin);
	//freopen("a.out","w",stdout);
	scanf("%d%d%d",&l,&r,&d);
	ans=r/d-l/d;
	if (l%d==0) ans++;
	printf("%d",ans); 
	return 0;
}