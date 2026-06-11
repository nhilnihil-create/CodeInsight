#include<bits/stdc++.h>
#define Tp template<typename Ty>
#define Ts template<typename Ty,typename... Ar>
#define Reg register
#define RI Reg int
#define Con const
#define CI Con int&
#define I inline
#define W while
#define N 100000
#define add(x,y) (a[++cnt]=x,b[cnt]=y,addE(x,y),addE(y,x))
#define addE(x,y) (e[++ee].nxt=lnk[x],e[lnk[x]=ee].to=y)
using namespace std;
int n,cnt,ee,s[2*N+5],p[N<<1],lnk[2*N+5],a[N<<1],b[N<<1];struct edge {int to,nxt;}e[N<<2];
I bool dfs(CI x,CI lst=0)
{
	if(p[n^s[x]^1]) return add(n,p[n^s[x]^1]),add(x,n<<1),true;p[s[x]]=x;
	for(RI i=lnk[x];i;i=e[i].nxt) if(e[i].to^lst&&(s[e[i].to]=s[x]^(e[i].to%n),dfs(e[i].to,x))) return true;
	return false;
}
int main()
{
	RI i,j,t;if(scanf("%d",&n),n==1) return puts("No"),0;
	for(i=2;i<n;i+=2) add(i,i+1),add(i+1,1),add(1,n+i),add(n+i,n+i+1);add(2,n+1);
	if(!(n&1)&&!dfs(s[1]=1)) return puts("No"),0;
	for(puts("Yes"),i=1;i<=cnt;++i) printf("%d %d\n",a[i],b[i]);
	return 0;
}