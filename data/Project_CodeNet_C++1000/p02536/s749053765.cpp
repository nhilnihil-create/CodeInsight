#include<bits/stdc++.h>
using namespace std;
// ---------------------------------------------------------------------------
/*https://atcoder.jp/contests/abl/tasks/abl_c
Algo : count number of connected components in graph 
16:23
*/
// ---------------------------------------------------------------------------

#define FASTIO	ios_base::sync_with_stdio(false),cin.tie(NULL),cout.tie(NULL)
#define ll long long 
#define mset(arr,val) memset(arr,val,sizeof(arr))
#define fi(a,b) for(int i=a;i<=b;++i)
#define fj(a,b) for(int j=a;j<=b;++j)
#define all(x) x.begin(),x.end()
// #define int long long

// ---------------------------------------------------------------------------
// Global Variables
const int mod = 1e9+7;
const int maxn = 2e5 + 9;
vector<int>graph[maxn];
bool vis[maxn];
// ---------------------------------------------------------------------------
void dfs(int node){
	vis[node]=true;
	for(auto child:graph[node]){
		if(!vis[child])dfs(child);
	}
}
// ---------------------------------------------------------------------------
void test_case(int tc)
{
	// cout<<"Case #"<<tc<<": ";
	int n,m;cin>>n>>m;
	fi(1,m){
		int u,v;cin>>u>>v;
		graph[u].push_back(v);
		graph[v].push_back(u);
	}
	int cc = 0;
	fi(1,n){
		if(!vis[i])dfs(i),cc++;
	}
	cout<<cc-1<<"\n";
}

int32_t main()
{
	FASTIO;
	#ifndef ONLINE_JUDGE
		freopen("/home/suryakant/input.txt","r",stdin);
		freopen("/home/suryakant/output.txt","w",stdout);
	#endif
	
    int t=1;
    //cin>>t;
    for(int tc=1;tc<=t;++tc)test_case(tc);
}