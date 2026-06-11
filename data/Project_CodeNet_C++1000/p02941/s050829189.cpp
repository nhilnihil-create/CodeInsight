#include<iostream>
#include<cstdio>
#include<algorithm>
#include<cmath>
#include<cstring>
#include<queue>
using namespace std;
#define MAXN 200000
#define Pr pair<int,int>
#define X first
#define Y second 
int n;
long long ans;
int a[MAXN+1],b[MAXN+1];
priority_queue <Pr> Q;
int main()
{
	scanf("%d",&n);
	for(int i=0;i<n;i++)
	scanf("%d",&a[i]);
	for(int i=0;i<n;i++)
	{
		scanf("%d",&b[i]);
		if(b[i]!=a[i]){
			Q.push(Pr(b[i],i));
		}
		if(b[i]<a[i]){
			printf("-1\n");
			return 0;
		}
	}
	while(!Q.empty()){
		int val=Q.top().X,pos=Q.top().Y,pval;
		Q.pop();
		if(!Q.empty()){
			pval=min(Q.top().X,max(b[(pos-1+n)%n],b[(pos+1)%n]));
		}else pval=max(b[(pos-1+n)%n],b[(pos+1)%n]);
		int dec=b[(pos-1+n)%n]+b[(pos+1)%n];
		int step=min(((val-pval)/dec)+1,(val-a[pos])/dec);
		b[pos]-=step*dec;
		//printf("%d %d\n",pos,b[pos]); 
		ans+=step;
		if(step<=0||a[pos]>b[pos]){
			printf("-1\n");return 0;
		}
		if(a[pos]<b[pos])Q.push(Pr(b[pos],pos));
	}
	printf("%lld",ans);
}