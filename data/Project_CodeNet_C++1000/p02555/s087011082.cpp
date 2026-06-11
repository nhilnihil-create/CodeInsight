#include<cstdio>
#include<set>
#include<stack>
#include<queue>
int main()
{
int s;
long long ans[2001];
scanf("%d",&s);
for(int i=0;i<2001;i++)
{
ans[i]=0;
}

for(int i=0;i<2001;i++)
{
	for(int j=0;j<=i-3;j++)
	{
		ans[i]=ans[i]+ans[j];
		ans[i]=ans[i]%1000000007;
	}
	if(i>=3){ans[i]++; ans[i]=ans[i]%1000000007;}
}
printf("%lld",ans[s]);
}