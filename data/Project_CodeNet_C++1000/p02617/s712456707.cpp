#include<cstdio>
int n,x,y;
long long ans;
int main() {
	scanf("%d",&n);
	for (long long i=1;i<=n;++i) ans+=i*(n-i+1);
	for (int i=1;i<n;++i) {
		scanf("%d%d",&x,&y);
		if (x>y) {int t=x; x=y; y=t;}
		ans-=(long long)x*(n-y+1);
	}
	printf("%lld",ans);
	return 0;
} 