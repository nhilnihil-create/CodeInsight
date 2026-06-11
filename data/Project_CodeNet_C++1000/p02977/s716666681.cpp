#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef double db;
const int N=100010,M=1000010,P=1e9+7;
const int inf=0x3f3f3f3f;
const int INF=0xcfcfcfcf;
const db eps=1e-9,pi=asin(1)*2;
inline ll read();
#define cmax(a,b) a=max(a,b)
#define cmin(a,b) a=min(a,b)
inline int ADD(int a,int b) { return a+b>=P?a+b-P:a+b; }
inline int MINUS(int a,int b) { return a-b<0?a-b+P:a-b; }
#define plus(a,b) a=ADD(a,b)
#define minus(a,b) a=MINUS(a,b)
#define mul(a,b) a=(1ll*a*(b))%P
#define mem(a,b) memset(a,b,sizeof(a))
#define pii pair<int,int>
#define pil pair<int,ll>
#define pli pair<ll,int>
#define pll pair<ll,ll>
#define mp(x,y) make_pair(x,y)
#define lowbit(x) ((x)&-(x))

int n,k;

#ifdef FILE
const int RS=1<<20;
char buf[RS],*p1=buf,*p2=buf;
#define getchar() p1==p2&&(p2=(p1=buf)+fread(buf,1,RS,stdin),p1==p2)?EOF:*p1++
#endif
inline ll read()
{
	ll s=0;
	bool flag=false;
	char ch=getchar();
	for(;ch<'0'||ch>'9';ch=getchar()) if(ch=='-') flag=true;
	for(;'0'<=ch&&ch<='9';ch=getchar()) s=(s<<3)+(s<<1)+(ch^'0');
	if(flag) return -s;
	return s;
}

int main()
{
#ifdef FILE
	freopen(FILE ".in","r",stdin);
	freopen(FILE ".out","w",stdout);
#endif
	n=read();
	if(lowbit(n)==n)
	{
		printf("No\n");
		return 0;
	}
	printf("Yes\n");
	if(n==3)
	{
		printf("1 2\n2 3\n3 4\n4 5\n5 6\n");
		return 0;
	}
	for(k=1;(k<<1)<=n;k<<=1);
	for(int i=1;i<k-1;i++) printf("%d %d\n",i,i+1);
	printf("%d %d\n",k-1,n+1);
	for(int i=1;i<k-1;i++) printf("%d %d\n",n+i,n+i+1);
	printf("%d %d\n",n+k,1);
	printf("%d %d\n",n+k,k+1);
	printf("%d %d\n",n+k+1,1);
	printf("%d %d\n",k,n+k+1);
	for(int i=k+2;i<=n;i++)
	{
		printf("%d %d\n",i,n+i-1);
		printf("%d %d\n",n+i,i-k);
	}
	return 0;
}