#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define REP(i,a,b) for(int i=(a),_end_=(b);i<=_end_;i++)
#define DREP(i,a,b) for(int i=(a),_end_=(b);i>=_end_;i--)
#define EREP(i,u) for(int i=start[u];i;i=e[i].next)
#define fi first
#define se second
#define mkr(a,b) make_pair(a,b)
#define SZ(A) ((int)A.size())
template<class T>inline void chkmin(T &a,T b){ if(a>b)a=b;}
template<class T>inline void chkmax(T &a,T b){ if(a<b)a=b;}
inline int read()
{
	int s=0,f=1;char ch=getchar();
	while(!isdigit(ch) && ch!='-')ch=getchar();
	if(ch=='-')ch=getchar(),f=-1;
	while(isdigit(ch))s=s*10+ch-'0',ch=getchar();
	return ~f?s:-s;
}

int n;

inline void init()
{
	n=read();
	if(__builtin_popcount(n)==1)puts("No"),exit(0);
	puts("Yes");
	REP(i,1,2)printf("%d %d\n",i,i+1);
	printf("%d %d\n",3,1+n);
	REP(i,1,2)printf("%d %d\n",i+n,i+n+1);
	REP(k,2,n-1>>1)
	{
		int a=k*2,b=k*2+1;
		printf("%d %d\n",a,b); printf("%d %d\n",b,1+n);
		printf("%d %d\n",1+n,a+n); printf("%d %d\n",a+n,b+n);
	}
	if(~n&1)
	{
		int x,y;
		int now=__builtin_clz(n);
		x=1<<31-now; y=n^x^1;
		printf("%d %d\n",n,x+n);
		printf("%d %d\n",n<<1,y);
	}
}

int main()
{
	init();
	
	return 0;
}
