#include<stdio.h>
#include<string.h>
int x[15],l[15],r[15];
int kase;
void dfs(int i,int j,int k)//i 是当前下落的球，j是左?的桶的第几个球，k 是右?放入
{
	if(i>10)//如果可以全部下落，肯定?足
	{
		kase=1;
		return;
	}
	if(kase)
	{
		return;
	}
	if(x[i]>l[j-1])//??落在左?
	{
		l[j]=x[i];dfs(i+1,j+1,k);
	}
	if(x[i]>r[k-1])//??落在右?
	{
		r[k]=x[i];dfs(i+1,j,k+1);
	}
}
int main()
{
	int t; 
	//freopen("shuju.txt","r",stdin);
	scanf("%d",&t);
	while(t--)
	{
		for(int i=1;i<=10;++i)
		{
			scanf("%d",&x[i]);
		}
		kase=0;
		dfs(1,1,1);
		if(kase)
		{
			printf("YES\n");
		}
		else
		{
			printf("NO\n");
		}
	}
	return 0;
} 