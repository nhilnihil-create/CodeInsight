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
int n,tong[300001],x,f[300001],s[300001];
inline bool cmp(const int &x,const int &y) {return x>y;}
int main()
{
	read(n);
	for(res i=1;i<=n;++i) read(x),++tong[x];
	sort(tong+1,tong+1+n,cmp);int p=1,now=1;
	s[n]=tong[n];for(res i=n-1;i;--i) s[i]=s[i+1]+tong[i];
	for(res i=n;i;--i) {
		for(;p<=n&&tong[p]>=i;++p);
		int sum=(p-1)*i+s[p];sum/=i;
		while(now<=sum) f[now++]=i;
	}
	for(res i=1;i<=n;++i) print(f[i],'\n');
	return 0;
}
/* stuff you should look for
    * int overflow, array bounds
    * special cases (n=1?), set tle
    * do something instead of nothing and stay organized
*/ 