#include<cstdio>
#include<cstring>
#include<iostream>
#include<algorithm>
using namespace std;//ans=sum^part+part
typedef long long ll;
const int N=1e5+4;
ll a[N],b[64],sum,cur;
int pos[64],tim;
int n;
inline void add(ll x) {
	for (int i=1;i<=tim;++i) {
		if (!((x>>pos[i])&1)) continue;
		else if (!b[pos[i]]) {b[pos[i]]=x;break;}
		else x^=b[pos[i]];
	}
}
int main() {
	scanf("%d",&n);
	for (register int i=1;i<=n;++i) {
		scanf("%lld",&a[i]);
		sum^=a[i];
	}
	for (int i=60;~i;--i)
		if (!((sum>>i)&1))
			pos[++tim]=i;
	for (register int i=1;i<=n;++i)
		add(a[i]);
	for (int i=1;i<=tim;++i)
		if (!((cur>>pos[i])&1))
			cur^=b[pos[i]];
	printf("%lld\n",(sum^cur)+cur);
	return 0;
}