#include<bits/stdc++.h>
#define int long long
using namespace std;
const int maxn=1e5+10;
const int p=1e9+7;
vector<int>v[maxn];
int n,k,fa[maxn],ans=1;
void dfs(int u,int f=0,int dep=1,int c=0)
{
	fa[u]=f;
	int cnt=0;
	for(int i=0;i<v[u].size();i++)
	{
		if(v[u][i]==f)continue;
		dfs(v[u][i],u,dep+1,cnt++);
	}
	int tmp=k-c;
	if(dep==2)tmp--;
	if(dep>2)tmp-=2;
//	printf("%lld %lld\n",u,tmp);
	ans=(ans*tmp)%p;
}
main()
{
	scanf("%lld%lld",&n,&k);
	for(int i=1,tmp1,tmp2;i<n;i++)
	{
		scanf("%lld%lld",&tmp1,&tmp2);
		v[tmp1].push_back(tmp2);
		v[tmp2].push_back(tmp1);
	}
	dfs(1);
	printf("%lld",ans);
}