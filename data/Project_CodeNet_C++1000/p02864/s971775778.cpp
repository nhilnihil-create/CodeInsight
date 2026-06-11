#include<bits/stdc++.h>
using namespace std;
#define res register int
#define ll long long
//#define cccgift
//#define getchar()(p1==p2&&(p2=(p1=buf)+fread(buf,1,1<<21,stdin),p1==p2)?EOF:*p1++)
//char buf[1<<21],*p1=buf,*p2=buf;
template<typename T>
inline void read(T &x)
{
    static char ch;bool f=1;
    for(x=0,ch=getchar();!isdigit(ch);ch=getchar()) if(ch=='-') f=0;
    for(;isdigit(ch);x=(x<<1)+(x<<3)+(ch^48),ch=getchar());x=f?x:-x;
}
template<typename T>
void print(T x)
{
    if (x<0) x=-x,putchar('-');
    if (x>9) print(x/10);
    putchar(x%10+48);
}
template<typename T>
inline void print(T x,char ap) {print(x);if (ap) putchar(ap);}
template<typename T>
inline void chkmax(T &x,const T &y) {x=x<y?y:x;}
template<typename T>
inline void chkmin(T &x,const T &y) {x=x<y?x:y;}
ll f[310][310];
int n,m,a[310];
int main()
{
	ios::sync_with_stdio(false);
	cin>>n>>m;
	for(res i=1;i<=n;++i) cin>>a[i];
	memset(f,0x3f,sizeof(f)),f[0][0]=0;
	for(res i=1;i<=n+1;++i)
	  for(res j=0;j<=m;++j)
	    for(res k=0;k<i;++k) if(j>=i-k-1) chkmin(f[i][j],f[k][j-(i-k-1)]+max(0,a[i]-a[k]));
	ll minn=1e18;
	for(res i=0;i<=m;++i) chkmin(minn,f[n+1][i]);
	cout<<minn<<'\n';
	cout<<flush;
	return 0;
}
/* stuff you should look for
    * int overflow, array bounds
    * special cases (n=1?), set tle
    * do something instead of nothing and stay organized
*/ 