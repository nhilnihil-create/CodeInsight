#include<bits/stdc++.h>
using namespace std;
typedef long long LL;
const int maxn=15;
int a[maxn]; int n;
void dfs(int pos,int limit)
{
	if(pos==n+1)
	{
		for(int i=1;i<=n;i++) printf("%c",a[i]+'a'-1);
		printf("\n");
		return ;
	}
	for(int i=1;i<=limit;i++)
	{
		a[pos]=i;
		dfs(pos+1,limit+(i==limit));
	}
}
int main(void)
{
	scanf("%d",&n);
	dfs(1,1);
	return 0;
}