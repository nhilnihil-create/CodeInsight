#include<cstring>
#include<cstdio>
#include<iostream>
#include<algorithm>
#include<vector>
#include<cmath>
#include<map>
#include<cmath>
#include<queue>
#include<bitset>
#include<cstdlib>
#include<set>
#include<unordered_map>
#define l(x) (x<<1)
#define r(x) ((x<<1)|1)
#define low(x) (x&(-x))
#define IL inline
#define reg register
#define LL long long
#define N 1000010
#define MOD 998244353
#define MO 1000000007
#define INF 0x3f3f3f3f
using namespace std;

LL T,n,m,i,j,k,x,y,z,Ans,sum,cnt;
LL a[N],b[N],p[N],v[N];
char c[N];

struct Data{
	LL x,y;
}d[N];

IL LL Abs(LL x){return (x<0)?-x:x;}
IL void Swap(LL &a,LL &b){a^=b^=a^=b;}
IL LL Min(LL a,LL b){return (a<b)?a:b;}
IL LL Max(LL a,LL b){return (a>b)?a:b;}
IL bool cmp(const Data a,const Data b){return a.x<b.x;}

IL LL Mi(LL x,LL y){
	LL p=x,t=1,Res=1;
	for (;t<=y;(t&y)?Res=(Res*p)%MOD:0,p=(p*p)%MOD,t<<=1);
	return Res;
}

IL LL read(){
	LL p=0,f=1;	char	c=getchar();
	while (c<48||c>57)	{if (c=='-')	f=-1;	c=getchar();}
	while (c>=48&&c<=57)	p=(p<<1)+(p<<3)+c-48,c=getchar();
	return p*f;
}

inline int Gcd(int x,int y){return (y==0)?x:Gcd(y,x%y);}

int main(){
	#ifdef __Marvolo
	freopen("zht.in","r",stdin);
	freopen("zht.out","w",stdout);
	#endif
	n=read();
	for (i=1;i<=n;i++)	a[i]=read();
	a[0]=a[1];
	for (i=1;i<=n;i++)	a[0]=Gcd(a[0],a[i]);
	if (a[0]!=1){
		puts("not coprime");
		return 0;
	}

	for (i=2;i<=1000000;i++){
		if (v[i])	continue;
		++cnt;	p[cnt]=i;	v[i]=i;
		for (j=i*i;j<=1000000;j+=i)
			if (!v[j])	v[j]=i;
	}
	v[1]=1;
	for (i=1;i<=n;i++){
		x=a[i];
		while (v[x]>1){
			if (b[v[x]] && b[v[x]]!=i)	goto END;
			b[v[x]]=i;	x/=v[x];
		}
	}
	puts("pairwise coprime");
	return 0;
	END:;
	puts("setwise coprime");
	return 0;
}