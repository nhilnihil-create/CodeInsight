#include<bits/stdc++.h>
#define ll long long
using namespace std;
const int mod=1e9+7;
ll m,n,ans=1; 
vector<ll> yy[100005];
inline void dfs(ll deep,ll fa,ll now,ll bro)
{
	ans=ans*bro%mod;
	ll sum,e=yy[now].size(),hh=0;
	if(deep==1) sum=n-1;
	else sum=n-2;
	for(int i=0;i<e;++i)
	{
		if(yy[now][i]==fa) {hh++; continue;}
		dfs(deep+1,now,yy[now][i],sum-i+hh);
	}
}
int main()
{
    std::ios::sync_with_stdio(0); std::cin.tie(0);
    cin>>m>>n;
    ll a,b;
    for(int i=1;i<m;++i)
    {
    	cin>>a>>b;
    	yy[a].push_back(b);
    	yy[b].push_back(a);
	}
	dfs(1,0,1,n);
	cout<<ans;
	return 0;
}