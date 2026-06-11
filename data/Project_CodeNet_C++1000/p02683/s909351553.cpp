#include<cstdio>
#include<algorithm>
#include<cstring>
using namespace std;
typedef long long ll;

int N,M,X,n;
ll cost,mi;
int B[20],ans[20];	//B是每个算法的总理解度
bool flag;

struct node
{
	int A[20],C;	//A是书能给的理解度 ，C是书的钱 
}nod[20];

void dfs(int u,int last)
{
	if(u==n)
	{
		cost=0;
		memset(B,0,sizeof(B));
		for(int i=0;i<u;i++)
		{
			for(int j=0;j<M;j++)
			{
				B[j]+=nod[ans[i]].A[j];
			}
			cost+=nod[ans[i]].C;
		}
		flag=true;
		//printf("cost=%d",cost) ;
		for(int i=0;i<M;i++)
		{
			if(B[i]<X)
			{
				flag=false;
				break;
			}
		}
		if(flag)
		{
			mi=min(cost,mi);
		}
		return ;
	}
	for(int i=1;i<=N;i++)
	{
		if(i>last)
		{
			last=i;
			ans[u]=i;
			dfs(u+1,last);
		}
		
	}
	
}

int main()
{
	scanf("%d%d%d",&N,&M,&X);
	for(int i=1;i<=N;i++)
	{
		scanf("%d",&nod[i].C);
		for(int j=0;j<M;j++)
		{
			scanf("%d",&nod[i].A[j]);
		}
	}
	mi=1e10;
	for(n=1;n<=N;n++)
	{
		dfs(0,0);
	}
	if(mi==1e10)
	{
		printf("-1");
	}
	else
	{
		printf("%lld",mi);
	}
	return 0;
	
}