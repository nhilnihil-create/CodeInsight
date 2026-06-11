//----------BHAVIK DIWANI(PICT_COMP)---------------
#include<bits/stdc++.h>
#define test ll t; cin>>t; while(t--)
#define fastio ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
#define mod 1000000007
#define ll long long
#define int long long
#define ull unsigned long long
#define MAX 1000005
#define pb push_back
#define mkp make_pair
#define vi vector<int>
#define pii pair<int,int>
#define endl '\n'
#define vs vector<string>
#define mii map<int,int>
#define msi map<string,int>
#define vpii vector< pair<int, int > >
#define vpsi vector< pair< string ,int > >
#define forci(p,q) for(int i=p;i<q;i++)
using namespace std;
vector<int> adj[200005];
bool vis[200005]={0};
int parent[200005]={0};
int ans[200005]={0};
void bfs(int n){
	queue<int> que;
	que.push(1);
	vis[1]=true;
	while(!que.empty()){
		int x=que.front();
		int cost=ans[x];
		que.pop();
		for(int i=0LL;i<adj[x].size();i++){
			int b=adj[x][i];
			if(!vis[b]){
				que.push(b);
				vis[b]=true;
				parent[b]=x;
				ans[b]+=cost;
			}
		}
	}
	
}
int solve()
{
	int n,q;	cin>>n>>q;
	for(int i=1LL;i<n;i++){
		int x,y;
		cin>>x>>y;
		adj[x].pb(y);
		adj[y].pb(x);
	}
	for(int i=1;i<=q;i++){
		int x,p;
		cin>>x>>p;
		ans[x]+=p;
	}
	bfs(n);
	for(int i=1LL;i<=n;i++){
		cout<<ans[i]<<" ";
	}
	return 0;
}
signed main()
{
	fastio;
//	test
		solve();
}