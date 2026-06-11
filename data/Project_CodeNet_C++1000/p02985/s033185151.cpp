#include<bits/stdc++.h>
#define LL long long
using namespace std;

const int mn=1e5+7,mod=1e9+7;
int n,k;
LL fac[mn],inv[mn];
vector<int> to[mn];

LL poww(LL a,LL b) {LL ans=1;while(b) {if(b&1) (ans*=a)%=mod;(a*=a)%=mod;b>>=1;}return ans;}

LL calc(int a,int b)
{
	if(b>a) return 0;
	return (fac[a]*inv[a-b]%mod);
}

LL dfs(int x,int fa)
{
	int use=0,f=0;
	if(fa==0) use=k-1,f=1;
	else use=k-2;
	LL ans=calc(use,to[x].size()-1+f);
	for(int i=0;i<to[x].size();++i) {
		int t=to[x][i];
		if(t==fa) continue;
		ans=(ans*dfs(t,x))%mod;
	}
	return ans;
}
	

int main()
{
	scanf("%d%d",&n,&k);
	for(int i=1;i<n;++i) {int a,b;scanf("%d%d",&a,&b);to[a].push_back(b),to[b].push_back(a);}
	fac[0]=inv[0]=1;
	for(int i=1;i<=k;++i) fac[i]=fac[i-1]*i%mod;
	inv[k]=poww(fac[k],mod-2);
	for(int i=k-1;i>=1;--i) inv[i]=inv[i+1]*(i+1)%mod;
	printf("%lld",(k*dfs(1,0))%mod);
}