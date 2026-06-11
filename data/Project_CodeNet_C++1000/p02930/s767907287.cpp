#include<iostream>
#include<cstdio>
#include<cstring>
#include<string>
#include<algorithm>
#include<cctype>
#include<cmath>
#include<cstdlib>
#include<queue>
#include<ctime>
#include<vector>
#include<set>
#include<map>
#include<stack>
using namespace std;
int res[510][510];
void dfs(int l,int r,int deep)
{
//	cout<<l<<" "<<r<<endl;
	if(l+1==r)
	{
		res[l][r]=deep;res[r][l]=deep;return;
	}
	if(l==r) return;
	for(int i=l;i<=(l+r)/2;i++)
	{
		for(int j=(l+r)/2+1;j<=r;j++)
		{
			res[i][j]=deep;
			res[j][i]=deep;
		}
	}
	dfs(l,(l+r)/2,deep+1);
	dfs((l+r)/2+1,r,deep+1);
}
int main()
{
	int n;
	scanf("%d",&n);
	dfs(1,n,1);
	for(int i=1;i<n;i++)
	{
		for(int j=i+1;j<=n;j++)
		{
			printf("%d ",res[i][j]);
		}
		printf("\n");
	}
 } 