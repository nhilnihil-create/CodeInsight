#include<bits/stdc++.h>
using namespace std;
 
#define IOS ios::sync_with_stdio(false);cin.tie(0);cout.tie(0);
#define endl "\n"
const int N=1e9+7;
#define int long long
#define double long double
#define pb push_back
#define vi vector<int>
#define rep(i,n) for(int i=1;i<=n;i++)
vi ar[100001];
int vis[100001];
void dfs(int node)
{
	vis[node]=1;
	for(int child:ar[node])
	{
		if(!vis[child])
			dfs(child);
	}
}
int32_t main()
{
  #ifndef ONLINE_JUDGE
      freopen("input.txt", "r", stdin);
      freopen("output.txt", "w", stdout);
  #endif
 IOS;
int n,m,a,b;
cin>>n>>m;
while(m--)
{
cin>>a>>b;
ar[a].pb(b),ar[b].pb(a);
}
int cc=0;
for(int i=1;i<=n;i++)
{
	if(!vis[i])
	{
		cc++;
		dfs(i);
	}
}
cout<<cc-1;
 
 	
 	
 	
 		
 	 
 	 	
 	 
 

 	



  
 




  
return 0;
}
