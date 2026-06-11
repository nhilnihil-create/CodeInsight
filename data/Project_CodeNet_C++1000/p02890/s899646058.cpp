#include <cstdio>

const int MAXN=3e5+5;
int cnt[MAXN],sum[MAXN]; //sum[i]=sum_{ak<=i}{ak}+sum_{ak>i}{1}
int ans[MAXN];

int main(){
	int n;
	scanf("%d",&n);
	for(int i=1,x;i<=n;++i){
		scanf("%d",&x);
		++sum[++cnt[x]];
	}
	for(int i=2;i<=n;++i)
		sum[i]+=sum[i-1];
	for(int i=n,m=0;i;--i){
		while(i*(m+1)<=n && sum[m+1]>=i*(m+1))
			++m;
		ans[i]=m;
	}
	for(int i=1;i<=n;++i)
		printf("%d\n",ans[i]);
	return 0;
}