#include "bits/stdc++.h"
using namespace std;

const int N=1e5+20;

int x,y,a,b,c,va[N],vb[N],vc[N];
priority_queue <int> pq;
long long ans;

int main()
{
	scanf("%d%d%d%d%d",&x,&y,&a,&b,&c);
	for(int i=0;i<a;i++) scanf("%d",&va[i]);
	for(int i=0;i<b;i++) scanf("%d",&vb[i]);
	for(int i=0;i<c;i++) scanf("%d",&vc[i]);

	sort(va,va+a);
	sort(vb,vb+b);
	for(int i=a-x;i<a;i++) pq.push(va[i]);
	for(int i=b-y;i<b;i++) pq.push(vb[i]);
	for(int i=0;i<c;i++) pq.push(vc[i]);

	int r=x+y;
	while(r--) ans+=pq.top(),pq.pop();
	printf("%lld",ans);
}