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

void dfs(int u)
{
	V[u]=true;
	for(int i=0;i<G[u].size();i++)
	{
		if(!V[G[u][i]])dfs(G[u][i]);
	}
	out.push_front(u);
	return;
}

void topologicalsort()
{
	for(int i=0;i<n;i++)V[i]=false;
	for(int i=0;i<n;i++)if(!V[i])dfs(i);
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