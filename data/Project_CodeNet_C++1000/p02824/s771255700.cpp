#include<bits/stdc++.h>

using namespace std;

typedef long long LL;
#define N 120000

LL n,m,v,p,ans,a[N];

bool check(LL x){
	LL t=max(v-(p-1)-(n-x)-1,0LL)*m,tmp=0;
	for (LL i=p;i<x;++i)
		if (a[x]+m<a[i]) return 0;
		else tmp+=a[x]+m-a[i];
	return tmp>=t;
}

int main(){
	scanf("%lld%lld%lld%lld",&n,&m,&v,&p);
	for (LL i=1;i<=n;++i) scanf("%lld",a+i);
	sort(a+1,a+n+1,greater<LL>());
	LL l=p+1,r=n; ans=p;
	while (l<=r){
		LL mid=(l+r)>>1;
		if (check(mid)){ans=mid; l=mid+1;}
		else r=mid-1;
	}
	printf("%lld\n",ans);
	
	return 0;
}
			