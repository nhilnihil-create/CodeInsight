#include <cstdio>
#include <cstring>
#include <cmath>
#include <iostream>
#include <algorithm>
#include <queue>
#include <set>
#include <vector>
#include <stack>
#include <map>
#include <ctime>
#define ri register
#define inf 0x7fffffff
#define E (1)
#define mk make_pair
#define int long long
using namespace std; const int N=3010, Mod=998244353;
inline int read()
{
	int s=0, w=1; ri char ch=getchar();
	while(ch<'0'||ch>'9') {if(ch=='-') w=-1; ch=getchar(); }
	while(ch>='0'&&ch<='9') s=(s<<3)+(s<<1)+(ch^48), ch=getchar(); return s*w;
}
void print(int x) {if(x<0) x=-x, putchar('-'); if(x>9) print(x/10); putchar(x%10+'0'); }
int n,S;
int a[N],dp[N][N],G;
inline int ksc(int x,int p) {int res=1; for(;p;p>>=1, x=x*x%Mod) if(p&1ll) res=res*x%Mod; return res; } 
signed main()
{
	G=ksc(2,Mod-2);
	n=read(), S=read();
	for(ri int i=1;i<=n;i++) a[i]=read();
	dp[0][0]=ksc(2,n);
	for(ri int i=1;i<=n;i++)for(ri int k=0;k<=S;(dp[i][k]+=dp[i-1][k])%=Mod, k++)
	if(a[i]<=k)dp[i][k]=dp[i-1][k-a[i]]*G%Mod;
	printf("%lld\n",dp[n][S]);
	return 0;
}