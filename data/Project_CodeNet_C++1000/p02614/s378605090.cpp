#include<bits/stdc++.h>
using namespace std;

int h,w,k,sum;
int ans[70][40];
char s[10][10];

int main()
{
	int x;
	scanf("%d%d%d",&h,&w,&k);
	for(int i=1;i<=h;i++) scanf("%s",s[i]+1);
	for(int tt=0;tt<(1<<w)-1;tt++)
	{
		ans[tt][0]=1;
		for(int i=1;i<=h;i++)
		{
			x=0;
			for(int j=1;j<=w;j++) if((tt&(1<<(j-1)))==0&&s[i][j]=='#') x++; 
			for(int j=k-x;j>=0;j--) ans[tt][j+x]+=ans[tt][j];
		}
		sum+=ans[tt][k];
	}
	printf("%d\n",sum);
	return 0;
}