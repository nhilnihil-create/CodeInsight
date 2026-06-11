#include<cstdio>
#include<cstring>
#include<string>
#include<iostream>
#include<cmath>
#include<algorithm>
#include<queue>
#include<map>
#include<ctime>

using namespace std;

template <typename T>

inline T read()
{
	T x=0,f=1;char c=getchar();
	while(!isdigit(c))
	{if(c=='-') f=-f;c=getchar();}
	while(isdigit(c))
	{x=(x<<3)+(x<<1)+(c-48);c=getchar();}
	return x*f;
}

#define lint long long int
#define ulint unsigned lint

const int inf=1e9+1e7;
const int MAXN=1e5+1e1;
const int Mod=1e9+7;

lint dp[MAXN];

lint ans=0;
int n,k;

lint qpow(lint A,int B)
{

	lint res=1;

	while(B>0)
	{
		if(B&1) (res*=A)%=Mod;
		(A*=A)%=Mod;
		B>>=1;
	}

	return res;

}

int main(void)
{

	// freopen("testdata.in","r",stdin);
	// freopen("testdata.out","w",stdout);

	scanf("%d%d",&n,&k);

	for(int i=k;i>=1;i--)
	{
		int num=k/i;
		dp[i]=qpow((lint)num,n);
		for(int res=i+i;res<=k;res+=i)
			(dp[i]+=(Mod-dp[res])%Mod)%=Mod;
		(ans+=(dp[i]*i)%Mod)%=Mod;
	}

	printf("%lld\n",ans);

	return 0;

}