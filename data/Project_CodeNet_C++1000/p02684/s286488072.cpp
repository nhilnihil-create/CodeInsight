#include<bits/stdc++.h>
using namespace std;

const int maxlog=62,maxn=200005;
int n;
long long k,pow2[maxlog+1]={1};
int d[maxn][maxlog+1];

int main()
{
	for(int i=1;i<=maxlog;i++) pow2[i]=pow2[i-1]+pow2[i-1];
	scanf("%d%lld",&n,&k);int q=1;
	for(int i=1;i<=n;i++)
		scanf("%d",&d[i][0]);
	for(int i=1;i<=maxlog;i++)
		for(int j=1;j<=n;j++)
			d[j][i]=d[d[j][i-1]][i-1];
	while(q--)
	{
		int p=maxlog,pos=1;
		while(k>0)
		{
			while(pow2[p]>k) p--;
			pos=d[pos][p];
			k-=pow2[p];
		}
		printf("%d\n",pos);
	}
	return 0;
}