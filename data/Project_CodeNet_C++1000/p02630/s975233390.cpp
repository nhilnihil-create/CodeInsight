#include<cstdio>
#include<cstring>
#include<iostream>
#include<algorithm>
using namespace std;
typedef long long ll;
const int N=1e5+4;
int n,m;
int a[N],b[N];
int cnt[N];
ll sum;
inline int read() {
	int x=0,f=1;char c=getchar();
	while (c<'0'||c>'9') {if (c=='-') f=-1;c=getchar();}
	while (c>='0'&&c<='9') x=x*10+c-'0',c=getchar();
	return x*f;
}
int main() {
//	freopen("in.txt","r",stdin);
	n=read();
	for (register int i=1;i<=n;++i) {
		a[i]=read();
		++cnt[a[i]];
		sum+=a[i];
	}
	m=read();
	for (register int i=0;i<m;++i) {
		int x=read(),y=read();
		sum+=1ll*cnt[x]*(y-x);
		cnt[y]+=cnt[x];
		cnt[x]=0;
		printf("%lld\n",sum);
	}
	return 0;
}