#include<cstring>
#include<cstdio>
#include<iostream>
#include<algorithm>
#include<vector>
#include<cmath>
#include<map>
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
#define N 510
#define MOD 998244353
#define MO 1000000007
#define INF 0x3f3f3f3f
using namespace std;

LL T,n,i,j,k,x,y,z;
LL a[N],f[N];
char c[N];

IL int Abs(int x){return (x<0)?-x:x;}
IL void Swap(int &a,int &b){a^=b^=a^=b;}
IL int Min(int a,int b){return (a<b)?a:b;}
IL LL Max(LL a,LL b){return (a>b)?a:b;}

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

int main(){
	#ifdef __Marvolo
	freopen("zht.in","r",stdin);
	freopen("zht.out","w",stdout);
	#endif
	n=read();
	for (i=1;i<=n;i++)	a[i]=read();
	f[1]=1000;
	for (i=2;i<=n;i++){
		for (j=1;j<i;j++)	f[i]=Max(f[i],f[j]);
		for (j=1;j<i;j++){
			f[i]=Max(f[i],f[j]/a[j]*a[i]+f[j]%a[j]);
		}
	}
	cout<<f[n]<<endl;
	return 0;
}