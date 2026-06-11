#include<bits/stdc++.h>
using namespace std;

const int maxn=1e5+7;
int a[maxn],n,m,p,v;

bool cmp(int a,int b)
{
	return a>b;
}

bool check(int x)
{
	if(x<=p) return 1;
	if(a[x]+m<a[p]) return 0;
	long long t=0;
	t+=1ll*(p-1)*m+1ll*(n-x+1)*m;
	for(int i=p;i<x;++i) {
		t+=max(a[x]+m-a[i],0);
	}
	if(t>=1ll*m*v) return 1;
	else return 0;
}

int main()
{
	scanf("%d %d %d %d",&n,&m,&v,&p);
	for(int i=1;i<=n;++i) scanf("%d",a+i);
	sort(a+1,a+n+1,cmp);
	int l=1,r=n;
	while(l<r) {
		int mid=(l+r+1)>>1;
		if(check(mid)) l=mid;
		else r=mid-1;
	}
	printf("%d",l);
}