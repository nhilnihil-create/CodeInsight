#include<cstdio>
typedef long long ll;
int tot=0;
int main() {
	ll cnt=0,n,tmp;
	scanf("%lld",&n);
	tmp=n;
	for(register ll i=2;i*i<n;++i) {
		if((n-1)%i==0) {
			++cnt;
			if(i!=(n-1)/i) ++cnt;
		}
	}
	for(register ll i=2;i*i<=n;++i) {
		if(n%i==0) {
			tmp=n;
			while(tmp%i==0) tmp/=i;
			if(tmp%i==1) ++cnt;
			if(i*i==n) continue;
			tmp=n;
			while(tmp%(n/i)==0) tmp/=(n/i);
			if(tmp%i==1) ++cnt;
		}
	}
	if(n!=2) ++cnt;
	printf("%lld\n",cnt+1);
	return 0;
}