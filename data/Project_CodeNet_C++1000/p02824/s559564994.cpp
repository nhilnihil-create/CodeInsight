#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
int a[100010];
int main(void){
	int n,m,v,p;
	scanf("%d%d%d%d",&n,&m,&v,&p);
	for (int i=1;i<=n;++i){
		scanf("%d",&a[i]);
	}
	sort(&a[1],&a[n+1]);
	int l=0,r=n-p+1;
	while(l<r-1){
		int md=(l+r)>>1;
		ll tot=1ll*m*(v-p+1);
		int t=a[md]+m;
		for (int i=1;i<=n-p+1;++i){
			if (a[i]>=t) break;
			tot-=min(t-a[i],m);
		}
		bool f=1;
		if (tot>0) f=0;
		if (a[n-p+1]>t) f=0;
		if (f){
			r=md;
		}
		else{
			l=md;
		}
	}
	printf("%d",n-l);
	return 0;
}