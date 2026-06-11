#include<bits/stdc++.h>
using namespace std;

int main()
{
	int x,y,ans=0;
	scanf("%d%d",&x,&y);
	if(x==1&&y==1) puts("1000000");
	else
	{
		if(x<=3) ans+=4-x;
		if(y<=3) ans+=4-y;
		printf("%d\n",ans*100000);
	}
	return 0;
}