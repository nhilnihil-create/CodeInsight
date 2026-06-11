#include<cstdio>
#include<cmath>
#include<iostream>
#include<algorithm>
#include<cstring>
#include<cstdlib>
#include<queue>
#include<map>
#include<stack>
#include<set>
#include<vector>
#include<functional>
using namespace std;
typedef long long LL;
inline long long read()
{
	long long kk=0,f=1;
	char cc=getchar();
	while(cc<'0'||cc>'9'){if(cc=='-')f=-1;cc=getchar();}
	while(cc>='0'&&cc<='9'){kk=(kk<<1)+(kk<<3)+cc-'0';cc=getchar();}
	return kk*f;
}
LL n;
struct zj
{
	LL val,od;
}cun[2022];
bool cmp(zj a,zj b){return a.val>b.val;}
LL dp[2][2002];
int main()
{
	n=read();
	for(int i=1;i<=n;++i)
	{
		cun[i].val=read();cun[i].od=i;
	}
	sort(cun+1,cun+1+n,cmp);
	memset(dp,-1,sizeof(dp));
	dp[0][0]=0;
	for(int i=1;i<=n;++i)
	{
		int now=i&1,per=now^1;
		memset(dp[now],-1,sizeof(dp[now]));
		for(int j=0;j<=i;++j)
		{
			if(dp[per][j]!=-1)
			{
				dp[now][j+1]=
				max(dp[now][j+1],dp[per][j]+cun[i].val*abs(cun[i].od-(j+1)));
				dp[now][j]=
				max(dp[now][j],dp[per][j]+cun[i].val*abs(cun[i].od-(n-i+j+1)));
			}	
		}
	}
	LL asd=0;
	for(int i=0;i<=n;++i)asd=max(asd,dp[n&1][i]);
	printf("%lld\n",asd);
}