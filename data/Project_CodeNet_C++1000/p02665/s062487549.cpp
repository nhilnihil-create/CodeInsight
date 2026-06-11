#include<bits/stdc++.h>
using namespace std;
#define LL long long
#define debug(x) cerr<<#x<<" = "<<x
#define sp <<"  "
#define el <<endl
#define fgx cerr<<" ---------------------------------------------- "<<endl
#define uint unsigned int 
#define ULL unsigned long long
#define DB long double
#define LDB long double
#define pii pair<int,int>
#define mp make_pair
#define pb push_back
#define rint register int 
namespace IO{
	const int BS=(1<<23)+5; int Top=0;
	char Buffer[BS],OT[BS],*OS=OT,*HD,*TL,SS[20]; const char *fin=OT+BS-1;
	char Getchar(){if(HD==TL){TL=(HD=Buffer)+fread(Buffer,1,BS,stdin);} return (HD==TL)?EOF:*HD++;}
	void flush(){fwrite(OT,1,OS-OT,stdout),OS=OT;}
	void Putchar(char c){*OS++ =c;if(OS==fin)flush();}
	void write(int x){
		if(!x){Putchar('0');return;} if(x<0) x=-x,Putchar('-');
		while(x) SS[++Top]=x%10,x/=10;
		while(Top) Putchar(SS[Top]+'0'),--Top;
	}
	inline LL read(){
		LL nm=0; bool fh=true; char cw=getchar();
		for(;!isdigit(cw);cw=getchar()) fh^=(cw=='-');
		for(;isdigit(cw);cw=getchar()) nm=nm*10+(cw-'0');
		return fh?nm:-nm;
	}
} using namespace IO;
#define mod 998244353
namespace CALC{
	inline int add(int x,int y){return (x+y>=mod)?(x+y-mod):(x+y);}
	inline int mns(int x,int y){return (x-y<0)?(x-y+mod):(x-y);}
	inline int mul(int x,int y){return (LL)x*(LL)y%mod;}
	inline void upd(int &x,int y){x=(x+y>=mod)?(x+y-mod):(x+y);}
	inline void dec(int &x,int y){x=(x-y<0)?(x-y+mod):(x-y);}
	inline int qpow(int x,LL sq){int res=1;for(;sq;sq>>=1,x=mul(x,x))if(sq&1)res=mul(res,x);return res;}
}using namespace CALC;
#define M 500020
#define INF 1000000000000000000ll
int n;
LL a[M],b[M],mx[M],mi[M],ans;
int main(){
	n=read();
	for(int i=0;i<=n;i++) a[i]=read(),b[i]=a[i];
	if(a[0]>1){puts("-1");return 0;}
	if(a[0]==1){puts(n>0?"-1":"1");return 0;}
	mx[n]=mi[n]=0,ans=b[0]=1;
	for(int i=n-1;i>=0;--i) mx[i]=mx[i+1]+a[i+1],mi[i]=((mi[i+1]+a[i+1]+1)>>1);
	for(int i=1;i<=n;i++) if(mi[i]>mx[i]){puts("-1");return 0;}
	if(mi[0]>1||mx[0]<1){puts("-1");return 0;}
	for(int i=1;i<=n;++i)
		b[i]=min((b[i-1]<<1)-a[i],mx[i]),ans+=a[i]+b[i];
	printf("%lld\n",ans);
	return 0;
}