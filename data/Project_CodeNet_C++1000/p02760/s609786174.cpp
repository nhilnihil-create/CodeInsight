#include<cstdio>
#include<functional>
#include<algorithm>
#include<cstring>
using namespace std;
int main(void)
{
	int i,j,a[9],flg[9],b,n,f;
	int che[8][3]={{0,1,2},{3,4,5},{6,7,8},
					{0,3,6},{1,4,7},{2,5,8},
					{0,4,8},{2,4,6}};
	for(i=0;i<9;i++)	scanf("%d",&a[i]);
	for(i=0;i<9;i++)	flg[i]=0;
	scanf("%d",&n);
	for(i=0;i<n;i++)	{
		scanf("%d",&b);
		for(j=0;j<9;j++)	{
			if(b==a[j])	flg[j]=1;
		}
	}
	f=0;
	for(i=0;i<8;i++)	{
		if(flg[che[i][0]]==1 && flg[che[i][1]]==1 
		&& flg[che[i][2]]==1)	{
			f=1;	break;
		}
	}
	if(f==1)	printf("Yes\n");
	else printf("No\n");
	return 0;
}