#include<iostream>
#include<cstdio>
#include<queue>
using namespace std;

int main()
{
	int i,j,n,k,e[101][101],v[101],a,b,d[101],s;
	queue<int> Q;
	
	for(i=0;i<=100;i++)
	{
		for(j=0;j<=100;j++)
		{
			e[i][j]=0;
		}
		v[i]=0;
		d[i]=-1;
	}
	scanf("%d",&n);
	for(i=0;i<=n-1;i++)
	{
		scanf("%d%d",&a,&k);
		for(j=0;j<=k-1;j++)
		{
			scanf("%d",&b);
			e[a][b]=1;
		}
	}
	
	Q.push(1);
	d[1]=0;
	s=1;
	v[1]=1;
	while(Q.empty()!=1)
	{
		i=Q.front();
		for(j=1;j<=n;j++)
		{
			if(e[i][j]==1 && v[j]==0)
			{
				d[j]=d[i]+1;
				v[j]=1;
				Q.push(j);
			}
		}
		Q.pop();
	}
	for(i=1;i<=n;i++)
	{
		cout << i << " " << d[i] << endl;
	}
	return 0;
}