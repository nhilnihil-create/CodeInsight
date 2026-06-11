#include<cstdio>
#include<algorithm>
#define maxl 65
#define maxn 100005
#define LL long long
using namespace std;
int n,tot;
LL ans,sum,a[maxn],b[maxn],p[maxl];
inline LL read(){
	LL ret=0,f=1;char ch=getchar();
	while (ch<'0'||ch>'9'){if (ch=='-') f=-1;ch=getchar();}
	while (ch>='0'&&ch<='9') ret=ret*10+ch-'0',ch=getchar();
	return ret*f;
}
void insert(LL x){
	for (int i=1;i<=tot;i++)
	if (x&((LL)1<<b[i])){
		if (!p[i]){p[i]=x;break;}
		x^=p[i];
	}
}
int main(){
	n=read();
	for (int i=1;i<=n;i++) a[i]=read(),sum^=a[i];
	for (int i=61;i>=0;i--) if (!(sum&((LL)1<<i))) b[++tot]=i;
	for (int i=61;i>=0;i--) if (sum&((LL)1<<i)) b[++tot]=i;
	for (int i=1;i<=n;i++) insert(a[i]);
	for (int i=1;i<=tot;i++)
	if (!(ans&((LL)1<<b[i]))) ans^=p[i];
	printf("%lld\n",(ans^sum)+ans);
	return 0;
}