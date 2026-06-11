#include<bits/stdc++.h>
using namespace std;
#define int long long 
#define mp make_pair
#define pb push_back
#define pii pair<int,int>
#define F first
#define S second
int const M=2e5+10;
vector<int>adj[M];
int cnt[M],q[M];
main()
{
	int n,m,a,b;
	cin>>n>>m;
	int tail=0,head=0;
	for(int i=1;i<=m;i++)cin>>a>>b,adj[a].pb(b),cnt[b]++;
	for(int i=0;i<n;i++)
	{
		//sort(adj[i].begin(),adj[i].end());
		if(cnt[i]==0)
			q[head++]=i;
	}
	int tmp=0;
	while(head>tail)
	{
		tmp++;
		int now=q[tail++];
		for(int i=0;i<adj[now].size();i++)
		{
			int u=adj[now][i];
			cnt[u]--;
			if(cnt[u]==0)
				q[head++]=u;
		}
	}
	if(tmp==n){
		for(int i=0;i<head;i++)
			cout<<q[i]<<endl;
	}
	else cout<<"NO";
}