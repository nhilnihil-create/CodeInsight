#include <stdio.h>
int ans=0, n,m;
void dfs(int i, int s, int sum)
{
	if(sum==m && s==0)
	{
		ans++;
		return;
	}
	if(i==10 || s==0)return;
	dfs(i+1, s, sum);
	dfs(i+1, s-1, sum+i);
}
int main(void)
{
	while(1)
	{
		scanf("%d %d",&n,&m);
		if(n==0&&m==0)break;
		ans=0;
		dfs(0, n, 0);
		printf("%d\n",ans);
	}
	return 0;
}