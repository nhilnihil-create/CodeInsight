#if __has_include("debug.h")
    #include "debug.h"
#else  
#include <bits/stdc++.h>
using namespace std;
#define d(...) 2;
#endif

#define int long long int
#define ld long double

#define fast ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
#define endl "\n"      

#define all(c) (c).begin(),(c).end()
#define rall(c) (c).rbegin(),(c).rend()
#define ff first
#define ss second
#define eps 1e-10
#define PI acos(-1LL)

#define gcd(a,b)            __gcd((a),(b))
#define lcm(a,b)            ((a*b)/gcd(a,b))

void solve();
const int N=2e5;
vector<int>edge(N);
vector<pair<int,int>>g[N];

void dfs(int node,int p=-1,int col=-1)
{
	int color=0;
	for(auto child:g[node])
	{
		if(child.ff==p)
		{
			continue;
		}
		color++;
		if(color==col)
		{
			color++;
		}
		dfs(child.ff,node,color);
		edge[child.ss]=color;
	}
}

int32_t main()
{
    #ifdef DEBUG
	freopen("input.txt","r",stdin);
	freopen("output.txt","w",stdout);
    #endif 

    fast
    
    int t = 1;
	// cin>>t;
	
	while(t--)
	    solve();
	return 0;  
}

void solve()
{
	int i,j;
	int n;
	cin>>n;
	for(i=1;i<=n-1;i++)
	{
		int a,b;
		cin>>a>>b;
		g[a].push_back({b,i});
		g[b].push_back({a,i});
	}

	int colors=INT_MIN;

	for(i=1;i<=n;i++)
	{
		colors=max(colors,(int)g[i].size());
	}

	d(colors);
	cout<<colors<<endl;

	dfs(1);

	for(i=1;i<=n-1;i++)
	{
		cout<<edge[i]<<endl;
	}

}