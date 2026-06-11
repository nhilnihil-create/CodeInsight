#include<bits/stdc++.h>
using namespace std;
#define N 1000005
int n,m,d[N];
struct mzls
{
	int a,b,id;
	bool operator<(const mzls &x1)const
	{
		return b<x1.b;
	}
}a1[N];
priority_queue<mzls>que;
int main()
{
	scanf("%d",&n);
	for(int i=1;i<=n;i++)
		scanf("%d",&a1[i].a),a1[i].id=i;
	for(int i=1;i<=n;i++)
		scanf("%d",&a1[i].b);
	for(int i=1;i<=n;i++)
	{
		if(a1[i].a>a1[i].b)
		{
			printf("-1");
			return 0;
		}
		if(a1[i].a!=a1[i].b)
			que.push(a1[i]);
	}
	long long ans=0;
	while(!que.empty())
	{
		mzls ml=que.top();
		que.pop();
		int d1=ml.id;
		int x1=d1-1,y1=d1+1;
		if(x1==0)
			x1=n;
		if(y1==n+1)
			y1=1;
		int x2=(ml.b-ml.a)/(a1[x1].b+a1[y1].b);
		if(!x2)
		{
			printf("-1");
			return 0;
		}
		ans+=x2;
		ml.b-=x2*(a1[x1].b+a1[y1].b);
		a1[ml.id].b-=x2*(a1[x1].b+a1[y1].b);
		if(ml.b!=ml.a)
			que.push(ml);
	}
	printf("%lld",ans);
}