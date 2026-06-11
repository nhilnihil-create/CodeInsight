#include<cstdio>
#include<cstring>
#include<iostream>
#include<algorithm>
using namespace std;
typedef long long ll;
const int N=2e5+4;
const int MOD=2019;
int n;
char s[N];
int sum[N];
int cnt[2020];
int fpow(int a,int b) {
	int ret=1;
	while (b) {
		if (b&1) ret=ret*a%MOD;
		b>>=1,a=a*a%MOD;
	}
	return ret;
}
int main() {
	scanf("%s",s+1);
	n=strlen(s+1);
	++cnt[0];
	for (register int i=n;i;--i) {
		sum[i]=(sum[i+1]+(s[i]-'0')*fpow(10,n-i))%MOD;
		++cnt[sum[i]];
	}
	ll ans=0;
	for (int i=0;i<2019;++i)
		ans+=1ll*cnt[i]*(cnt[i]-1)/2;
	printf("%lld\n",ans);
	return 0;
}