#include<bits/stdc++.h>
using namespace std;
#define cs const
#define re register
#define pb push_back
#define pii pair<int,int>
#define ll long long
#define fi first
#define se second
#define bg begin
cs int RLEN=1<<20|1;
inline char gc(){
    static char ibuf[RLEN],*ib,*ob;
    (ib==ob)&&(ob=(ib=ibuf)+fread(ibuf,1,RLEN,stdin));
    return (ib==ob)?EOF:*ib++;
}
inline int read(){
    char ch=gc();
    int res=0;bool f=1;
    while(!isdigit(ch))f^=ch=='-',ch=gc();
    while(isdigit(ch))res=(res+(res<<2)<<1)+(ch^48),ch=gc();
    return f?res:-res;
}
inline ll readll(){
    char ch=gc();
    ll res=0;bool f=1;
    while(!isdigit(ch))f^=ch=='-',ch=gc();
    while(isdigit(ch))res=(res+(res<<2)<<1)+(ch^48),ch=gc();
    return f?res:-res;
}
inline int readstring(char *s){
	int top=0;char ch=gc();
	while(isspace(ch))ch=gc();
	while(!isspace(ch)&&ch!=EOF)s[++top]=ch,ch=gc();
	return top;
}
template<typename tp>inline void chemx(tp &a,tp b){a<b?a=b:0;}
template<typename tp>inline void chemn(tp &a,tp b){a>b?a=b:0;}
cs int mod=1e9+7;
inline int add(int a,int b){return (a+=b)>=mod?(a-mod):a;}
inline int dec(int a,int b){a-=b;return a+(a>>31&mod);}
inline int mul(int a,int b){static ll r;r=1ll*a*b;return (r>=mod)?(r%mod):r;}
inline void Add(int &a,int b){(a+=b)>=mod?(a-=mod):0;}
inline void Dec(int &a,int b){a-=b,a+=a>>31&mod;}
inline void Mul(int &a,int b){static ll r;r=1ll*a*b;a=(r>=mod)?(r%mod):r;}
inline int ksm(int a,int b,int res=1){for(;b;b>>=1,Mul(a,a))(b&1)&&(Mul(res,a),1);return res;}
inline int Inv(int x){return ksm(x,mod-2);}
inline int fix(int x){return (x<0)?x+mod:x;}
cs int N=1000005;
int n,a[N],p[N],pw[N];
char s[N];
int main(){
	#ifdef Stargazer
	freopen("lx.in","r",stdin);
	#endif
	n=read();
	readstring(s);
	int fg=1;
	for(int i=1;i<=n;i++){
		a[i]=s[i]-'1';
		if(a[i]==1)fg=0;
	}
	if(fg){
		for(int i=1;i<=n;i++)a[i]/=2;
	}
	for(int i=1;i<=n;i++)
	pw[i]=(i&1?0:pw[i>>1]+1),p[i]=(p[i-1]+pw[i]); 
	int res=0;
	for(int i=1;i<=n;i++)
	if(p[n-1]==p[i-1]+p[n-i])
	(res+=a[i])&=1;
	cout<<res*(fg+1)<<'\n';
}