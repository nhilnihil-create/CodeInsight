#include <bits/stdc++.h>
using namespace std;
bool check(int *sum,int x,int m)
{
	for(int i=0;i<m;i++)
	{
		if(sum[i]<x) return 0;
	}
	return 1;
}
int main()
{
	int n,m,x,mini=1200007;
	cin>>n>>m>>x;
	int c[21],a[21][21];
	for(int i=0;i<n;i++)
	{
		cin>>c[i];
		for(int j=0;j<m;j++) cin>>a[i][j];
	}
	for(int i=0;i<(1<<n);i++)
	{
		int sum[50],cost=0;
		memset(sum,0,sizeof(sum));
		for(int j=0;j<n;j++)//枚举所有可能的方案，每一个i对应一个方案 
		{
			if(i&(1<<j))//i的第j位是1，在i的方案中包含j这本书 
			{
				for(int k=0;k<m;k++) sum[k]+=a[j][k];
				cost+=c[j];
			}
		}
		if(check(sum,x,m)==1)
		{
			if(mini>cost) mini=cost;
		}
	}
	if(mini==1200007) cout<<-1;
	else cout<<mini;
    return 0;
}