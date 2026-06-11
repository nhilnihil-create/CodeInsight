/***********************************************************
 *This code By @1353055672(Ligen)                          *
 *[Warning]You're not excepted to understand this code!    *
 *CSP-S 2019 RP++                                          *
 ***********************************************************/
#pragma GCC optimize(3)
#define ADD_STACK int size = 512 << 20;\
	char *pp = (char*)malloc(size) + size;  \
	__asm__("movl %0, %%esp\n" :: "r"(pp))
#include<iostream>
#include<stdio.h>
#include<algorithm>
#include<cmath>
#include<cstring>
#include<string>
#include<fstream>
#include<queue>
#include<map>
#include<stack>
#include<set>
#include<bitset>
#include<ctime>
#include<vector>
#define ll long long
#define ull unsigned long long
#define mn 200020
#define Max(x,y) (((x)>(y))?(x):(y))
#define Min(x,y) (((x)<(y))?(x):(y))
#define Abs(x) (((x)<(0))?(-(x)):(x))
#define infll (ll)(1e18)
#define infint (1<<30)
#define mod (int)(1e9+7)
#define FOR(a,b,c) for (register int a=b;a<=c;++a)
#define FORD(a,b,c) for (register int a=b;a>=c;--a)
using namespace std;
//char buf[1<<20],*p1=buf,*p2=buf;
//#define getchar() (p1==p2&&(p2=(p1=buf)+fread(buf,1,1<<20,stdin),p1==p2)?EOF:*p1++)
inline ll read(){
	ll x=0,f=1;char c;
	for(c=getchar();c<'0'||c>'9';f=((c=='-')?-1:f),c=getchar());
	for(;c>='0'&&c<='9';x=x*10+c-'0',c=getchar());
	return x*f;
}
template<typename T>
inline void write(T a){
	if(a==0){putchar('0');return;}if(a<0)putchar('-'),a=-a;char c1[120];int h=0;
	while(a)c1[++h]=a%10+'0',a/=10;FORD(i,h,1)putchar(c1[i]);
}
inline void write_(){return;}
template<typename T,typename... Args>
inline void write_(T a,Args... b){write(a);putchar(' ');write_(b...);}
inline void writeln(){putchar('\n');return;}
template<typename T,typename... Args>
inline void writeln(T a,Args... b){write(a);putchar(' ');writeln(b...);}
//need c++11

//inline void write(ll a){
//    if(a==0){putchar('0');return;}if(a<0)putchar('-'),a=-a;char c1[120];int h=0;
//    while(a)c1[++h]=a%10+'0',a/=10;FORD(i,h,1)putchar(c1[i]);
//}
//inline void write_(ll a){write(a);putchar(' ');}
//inline void writeln(ll a){write(a);putchar('\n');}
inline ll gcd(ll a,ll b){return a==0?b:gcd(b%a,a);}
inline ll lcm(ll a,ll b){return 1ll*a/gcd(a,b)*b;}
inline ll Pow(ll n,ll a){ll b=1;while(a){if(a&1)b=1ll*b*n%mod;n=1ll*n*n%mod;a>>=1;}return b;}
//---------------------Head Files--------------------------//
ll n,a[mn],p[120],num,ans;
inline void f(ll x){
	FORD(i,62,0)if(!(num&(1ll<<i))&&(x&(1ll<<i))){
		if(!p[i]){p[i]=x;return;}
		x^=p[i];
	}
	FORD(i,62,0)if((num&(1ll<<i))&&(x&(1ll<<i))){
		if(!p[i]){p[i]=x;return;}
		x^=p[i];
	}
}
signed main(){
#ifdef LOCAL_LIGEN
	// freopen("0.in","r",stdin);
	// freopen("0.out","w",stdout);
	double be=clock();
#endif
	n=read();
	FOR(i,1,n)a[i]=read(),num^=a[i];
	FOR(i,1,n)f(a[i]);
	FORD(i,62,0)if(!(ans&(1ll<<i)))ans^=p[i];
	writeln(ans+(num^ans));
#ifdef LOCAL_LIGEN
	double en=clock();
	printf("Time: %.0lfms\n",en-be);
	fclose(stdin);fclose(stdout);
#endif
	return 0;
}