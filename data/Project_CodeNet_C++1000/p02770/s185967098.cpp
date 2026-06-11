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
int k,q,d[5001],n,x,m,a[5001];
ll s[5001];
inline int getsum(int n,int x,int m) {
	ll tot=x%m;
	tot+=s[k-1]*(n/k)+((n%k)?s[n%k-1]:0);
	/*
	ll sum=x%m+s[k-1]*(n/k);
	for(res i=n/k*k+1;i<n;++i) sum+=a[(i-1)%k];print(sum,'\n');
	*/
	return tot/m;
}
int main()
{
	read(k),read(q);
	for(res i=0;i<k;++i) read(d[i]);
	while(q--) {
		read(n),read(x),read(m);
		for(res i=0;i<k;++i) a[i]=d[i]%m;
		s[0]=a[0];
		for(res i=1;i<k;++i) s[i]=s[i-1]+a[i];
		int tot=n-2-getsum(n-1,x,m);
		for(res i=0;i<k;++i) if(a[i]==0) {
			tot-=(n-1)/k;
			if(i<(n-1)%k) --tot;
		}
		print(tot+1,'\n');
	}
	return 0;
}
/* stuff you should look for
    * int overflow, array bounds
    * special cases (n=1?), set tle
    * do something instead of nothing and stay organized
*/ 