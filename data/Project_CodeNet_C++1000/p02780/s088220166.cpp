#include<cstdio>
#include<cstring>
#include<iostream>
#include<algorithm>
#include<map>
using namespace std;
typedef long long ll;
const int N=2e5+4;
int n,K;
double a[N];
double sum[N];
inline int read() {
	int x=0,f=1;char c=getchar();
	while (c<'0'||c>'9') {if (c=='-') f=-1;c=getchar();}
	while (c>='0'&&c<='9') x=x*10+c-'0',c=getchar();
	return x*f;
}
inline void smax(double &x,double y) {
	x=x<y?y:x;
}
int main() {
//	freopen("in.txt","r",stdin);
	n=read(),K=read();
	for (register int i=1;i<=n;++i) {
		a[i]=(double)read();
		a[i]=(a[i]+1)/2.0;
		sum[i]=sum[i-1]+a[i]; 
	}
	double ans=0.0;
	for (register int i=K;i<=n;++i)
		smax(ans,sum[i]-sum[i-K]);
	printf("%.8lf\n",ans);
	return 0;
}