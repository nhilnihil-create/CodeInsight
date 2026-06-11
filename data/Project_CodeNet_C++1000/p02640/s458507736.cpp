#include<cstdio>
#include<algorithm>
#include<functional>
#include<cstring>
using namespace std;
int main(void)
{
	int x,y,i,j,flg;
	scanf("%d %d",&x,&y);
	flg=0;
	for(i=0;i<=x;i++)	{
		j=x-i;
		if(i*2+j*4==y)	{
			flg=1;	break;
		}
	}
	if(flg==0)	printf("No\n");
	else printf("Yes\n");
	return 0;
}