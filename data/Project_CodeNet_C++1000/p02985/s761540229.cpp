#include <iostream>
#include <bits/stdc++.h>
#define ll long long
#define inf 100000000
#define mod 1000000007
#define ld long double
#define point complex<double>
#define pi  acos(-1)
#define IO                    \
	ios_base::sync_with_stdio(false); \
	cin.tie(NULL);                    \
	cout.tie(NULL);
using namespace std;
vector<int>graph[200000+5];
ll val[200000+5]={};
bool viss[200000+5];
ll solve(int cur)
{
	ll tmp=val[cur]%mod;
	if(viss[cur])return 1;
	viss[cur]=1;
	for(auto v:graph[cur])
	{
		tmp*=solve(v)%mod;;
		tmp%=mod;
	}
	 tmp%=mod;
	 return tmp;

}
int main()
{
    IO
	int n,k;
	cin>>n>>k;
	int a,b;
	for(int i=0;i<n-1;i++)
	{
		cin>>a>>b;
		a--;
		b--;
		graph[a].push_back(b);
		graph[b].push_back(a);
	}
	queue<int>q;
	val[0]=k;
	bool vis[n]={};
	q.push(0);
	int cnt=1;
	
	while(q.size())
	{
		int cur=q.front();
		q.pop();
		if(vis[cur]==1)continue;
		vis[cur]=1;
		if(cur==0)cnt=1;
		else cnt=2;
		for(auto g:graph[cur])
		{
			if(vis[g]==0)
			{
				val[g]=k-cnt;
				cnt++;
				q.push(g);
				if(val[g]==0)
				{
					cout<<0<<endl;
					return 0;
				}
			}
		}
	}

	cout<<solve(0);


    return 0;
}
