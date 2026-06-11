#include <bits/stdc++.h>
     
#define pll pair <long long,long long>
#define pb push_back
#define ll long long
#define ff first
#define ss second
#define vll vector <ll>
#define NFS ios_base::sync_with_stdio(0); cin.tie(NULL);
#define endl '\n'
#define M 1000000007   
using namespace std;

int n,m;
vector<int> v[100001];
bool vis[100001];
int dis[100001];

void solve()
{
	cin>>n>>m;
	while(m--)
	{
		int a,b;
		cin>>a>>b;
		v[a].pb(b);
		v[b].pb(a);
	}
	for(int i=1;i<=n;i++)
	{
		vis[i]=false;
		dis[i]=0;
	}
	queue<int> q;
	q.push(1);
	vis[1]=true;
	dis[1]=0;
	while(!q.empty())
	{
		int node = q.front();
		q.pop();
		for(auto ch:v[node])
		{
			if(!vis[ch])
			{
				q.push(ch);
				vis[ch]=true;
				dis[ch]=node;
			}
		}
	}
	for(int i=1;i<=n;i++)
	{
		if(!vis[i])
		{
			cout<<"No";return;
		}
	}
	cout<<"Yes"<<endl;
	for(int i=2;i<=n;i++)
		cout<<dis[i]<<endl;
}
 
int main()
{
#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
#endif
    NFS
 	int t=1;
 	//cin>>t;
 	while(t--)
 	{
 		solve();
 	}
    return 0;
}