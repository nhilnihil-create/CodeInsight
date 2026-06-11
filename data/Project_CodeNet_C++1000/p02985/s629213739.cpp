#include<iostream>
#include<cmath>
#include<cstring>
#include<cstdio>
#include<queue>
#include<algorithm>
#include<set>
#include<map> 
using namespace std;

const int mod=1e9+7;
const int N=1e5+10;
long long ans;
int n,k,w[N],first[N],to[2*N],nxt[2*N],tot,sum,num[N];
bool vis[N];
queue<int> q; 

void create(int x,int y)
{
	tot++;
	nxt[tot]=first[x];
	first[x]=tot;
	to[tot]=y;
}

void dfs(int u)
{
	for(int e=first[u];e;e=nxt[e])
	{
		int v=to[e];
		if(vis[v]==true) sum++;
		else q.push(v);
		sum+=num[v];
		num[v]++;
	}
}

int main()
{
	//freopen("lx.in","r",stdin);
	
	int x,y;
	scanf("%d%d",&n,&k);
	for(int i=1;i<n;i++)
	{
		scanf("%d%d",&x,&y);
		create(x,y);
		create(y,x);
		w[i]=k;
	}
	w[n]=k;
	q.push(1); vis[1]=true;ans=1;
	while(!q.empty())
	{
		sum=0;
		int z=q.front();q.pop();
		dfs(z);
		w[z]=w[z]-sum;
		vis[z]=true;
		if(w[z]==0)
		{
			ans=0;
			break;
		}
		ans=(ans*w[z])%mod;
	}

	printf("%lld",ans);
	
	return 0;
}