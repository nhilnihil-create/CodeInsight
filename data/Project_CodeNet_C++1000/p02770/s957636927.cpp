#include<bits/stdc++.h>
using namespace std;

const int maxn=5005;
int pd[maxn],z[maxn];
long long d[maxn];
int k,q,n,x,m;

int main()
{
	scanf("%d %d",&k,&q);
	for(int i=0;i<k;++i) scanf("%d",pd+i);
	while(q--) {
		scanf("%d %d %d",&n,&x,&m);
		for(int i=0;i<k;++i) d[i]=pd[i]%m;
		int ans=n-1;
		memset(z,0,sizeof z);
		for(int i=0;i<k;++i) {
			if(!d[i]) z[i]++;
			if(i) z[i]+=z[i-1];
		}
		ans-=(n-1)/k*z[k-1];
		if((n-1)%k) ans-=z[(n-1)%k-1];
		for(int i=1;i<k;++i) d[i]+=d[i-1];
		long long num=x+(n-1)/k*d[k-1];
		if((n-1)%k) num+=d[(n-1)%k-1];
		ans-=num/m-x/m;
		printf("%d\n",ans);
	}
}