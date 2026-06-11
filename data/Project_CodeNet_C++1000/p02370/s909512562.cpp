#include<iostream>
#include<cstdio>
#include<cstdlib>
#include<algorithm>
#include<vector>
#include<string>
#include<sstream>
#include<iomanip>
#include<utility>
#include<cmath>
#include<set>
#include<list>
#include<queue>
#include<stack>
#include<map>
#include<set>
using namespace std;
typedef long long int ll;
const int MAX=100000;

vector<int> G[MAX];
list<int> out;
bool V[MAX];
int n;
int indeg[MAX];

void bfs(int s)
{
	queue<int> q;
	q.push(s);
	V[s]=true;
	int u,v;
	
	while(!q.empty())
	{
		u=q.front();q.pop();
		out.push_back(u);
		for(int i=0;i<G[u].size();i++)
		{
			v=G[u][i];
			indeg[v]--;
			if(!V[v]&&indeg[v]==0)
			{
				V[v]=true;
				q.push(v);
			}
		}
	}
	
	return;
}

void topologicalsort()
{
	for(int i=0;i<n;i++)
	{
		indeg[i]=0;
		V[i]=false;
	}
	
	for(int u=0;u<n;u++)
	{
		for(int i=0;i<G[u].size();i++)
		{
			indeg[G[u][i]]++;
		}
	}
	
	for(int u=0;u<n;u++)if(!V[u]&&indeg[u]==0)bfs(u);
	
	for(auto it:out)cout<<it<<endl;
	
	return;
}

int main()
{
	int m;cin>>n>>m;
	int s,t;
	for(int i=0;i<m;i++)
	{
		cin>>s>>t;
		G[s].push_back(t);
	}
	topologicalsort();
	return 0;
}