#include<bits/stdc++.h>
using namespace std;

const int maxn=3e5+6;
int cnt[maxn],a,n,tot;
int d[maxn],sum[maxn],sumd[maxn];
long long f[maxn];

int main()
{
	scanf("%d",&n);
	for(int i=1;i<=n;++i) {
		scanf("%d",&a);
		cnt[a]++;
	}
	for(int i=1;i<=n;++i) d[cnt[i]]++;
	sumd[0]=d[0];
	for(int i=1;i<=n;++i) {
		sum[i]=sum[i-1]+i*d[i];
		sumd[i]=sumd[i-1]+d[i];
	}
	for(int i=1;i<=n;++i) {
		f[i]=(1ll*sum[i]+1ll*i*(sumd[n]-sumd[i]))/i;
	}
	int las=n;
	for(int i=1;i<=n;++i) {
		while(f[las]<i&&las!=0) las--;
		printf("%d\n",las);
	}
}