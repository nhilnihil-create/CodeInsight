#include<bits/stdc++.h>
using namespace std;
int n,m;
int main()
{
	scanf("%d%d",&n,&m);
	int l=1,r=m+1;
	while(l<r)
	{
		printf("%d %d\n",l,r);
		l++,r--;
	}
	l=m+2,r=m+m+1;
	while(l<r)
	{
		printf("%d %d\n",l,r);
		l++,r--;
	}
	return 0;
}