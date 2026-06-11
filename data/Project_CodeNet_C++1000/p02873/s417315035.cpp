#include<bits/stdc++.h>
using namespace std;
#define int long long
const int maxm=5e5+5;
vector<int>g[maxm];
char s[maxm];
int in[maxm];
int d[maxm];
int n;
signed main()
{
	scanf("%s",s+1);
	n=strlen(s+1);
	n++;
	for(int i=1; i<=n-1; i++)
	{
		if(s[i]=='>')
		{
			g[i+1].push_back(i);
			in[i]++;
		}
		else
		{
			g[i].push_back(i+1);
			in[i+1]++;
		}
	}
	queue<int>q;
	for(int i=1; i<=n; i++)
	{
		if(in[i]==0)
			q.push(i);
	}
	int ans=0;
	while(!q.empty())
	{
		int x=q.front();
		q.pop();
		ans+=d[x];
		for(int v:g[x])
		{
			if(in[v])
			{
				in[v]--;
				d[v]=max(d[v],d[x]+1);
				if(!in[v])
					q.push(v);
			}
		}
	}
	cout<<ans<<endl;
	return 0;
}
