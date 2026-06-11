#pragma GCC optimize ("O3")
#pragma GCC optimize("unroll-loops")
#pragma GCC target("sse4")
#include"bits/stdc++.h"
using namespace std;
typedef long long ll;
#define int ll
#define sz(x) (int)(x).size();
#define all(x) x.begin(), x.end()
#define trav(i,a) for(auto &i:a) 
inline int in(){int x;scanf("%lld",&x);return x;}
int g[20][20];
int32_t main()
{
	int n=in();int k,x,y;
	memset(g,-1,sizeof g);
	for(int i=0;i<n;i++)
	{
		k=in();
		while(k--)
		{
			x=in();y=in();
			g[i][--x]=y;
		}
	}
	int ans=0;
	for(int mask=0;mask<(1LL<<n);mask++)
	{
		bool ok=1;
		vector<int> d(n);
		for(int i=0;i<n;i++)
		{
			if(mask&(1LL<<i))d[i]=1;
		}
		for(int i=0;i<n;i++)
		{
			if(!d[i])continue;
			
			for(int j=0;j<n;j++)
			{
				if(g[i][j]==-1)continue;
				if(g[i][j]!=d[j])ok=0;
			}
			
		}
		if(ok)ans=max(ans,(int)__builtin_popcountll(mask));
		
	}
	cout<<ans;
	
	
	
}