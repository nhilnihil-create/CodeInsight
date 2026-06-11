#include<iostream>
#include<cstdio>
#include<cstdlib>
#include<cmath>
#include<cstring>
#include<algorithm>
#include<queue>
#define LL long long
#define inl inline
#define re register
#define MAXN 201000
using namespace std;
struct dig
{
	int d;
	LL c;
}g[MAXN];
int m;
int map[11][11],t[11][11];
int now;
LL ans;
void push(int x){ans+=t[now][x];now=map[now][x];}
void work(int d,LL c)
{
	if(c==0)return ;
	ans+=c/2*t[d][d];
	if(c&1)push(d);
	work(map[d][d],c/2);
}
int main()
{
	scanf("%d",&m);
	for(int i=0;i<=9;i++)
		for(int j=0;j<=9;j++)
		{
			map[i][j]=i+j;t[i][j]=1;
			while(map[i][j]>=10)
			{
				map[i][j]=map[i][j]/10+map[i][j]%10;
				t[i][j]++;
			}
		}
	for(int i=1;i<=m;i++)
	{
		int d;LL c;
		scanf("%d%lld",&d,&c);
		work(d,c);
	}
	cout<<ans-1;
	return 0;
}

