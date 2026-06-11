#include <bits/stdc++.h>
using namespace std;

const int M=1e5+5;
const int MO=1e9+7;
inline int add(int x,int y)
{
	x+=y;
	if(x>=MO) x-=MO;
	return x;
}
inline int sub(int x,int y)
{
	x-=y;
	if(x<0) x+=MO;
	return x;
}
inline int mul(int x,int y)
{
	return 1LL*x*y%MO;
}
inline void addv(int &x,int y)
{
	x+=y;
	if(x>=MO) x-=MO;
}
inline void subv(int &x,int y)
{
	x-=y;
	if(x<0) x+=MO;
}
inline void mulv(int &x,int y)
{
	x=1LL*x*y%MO;
}
 
int inv[M],fa[M],ifa[M];
void init()
{
	fa[0]=ifa[0]=1;
	inv[1]=fa[1]=ifa[1]=1;
    for(int i=2;i<M;i++)
    {
    	fa[i]=mul(fa[i-1],i);
    	inv[i]=mul(MO-MO/i,inv[MO%i]);
    	ifa[i]=mul(inv[i],ifa[i-1]);
    }
}
 
int C(int n,int m)
{
	if(n<m) return 0;
	return mul(mul(fa[n],ifa[m]),ifa[n-m]);
}

char s[M];
int dp[M][2];
int n;

int getdp(int cur,int lim)
{
	if(cur==n) return 1;
	int &ans=dp[cur][lim];
	if(ans!=-1) return ans;
	ans=0;
	int up=lim?s[cur]-'0':1;
	for(int i=0;i<=up;i++)
	{
		if(i==0) addv(ans,getdp(cur+1,lim&&i==up));
		else addv(ans,mul(2,getdp(cur+1,lim&&i==up)));
	}
	return ans;
}

int main()
{
	scanf("%s",s);
	n=strlen(s);
	init();
	memset(dp,-1,sizeof(dp));
	printf("%d\n",getdp(0,1));
	return 0;
}