#include<bits/stdc++.h> 

using namespace std;

const int MAXN=10010;

typedef vector<int> vec;
typedef vector<vec> Graph;

Graph G(MAXN);
vec d(MAXN);

int main()
{
	int n,e;
	scanf("%d%d",&n,&e);
	for(int i=0;i<e;i++)
	{
		int s,t;
		scanf("%d%d",&s,&t);
		G[s].push_back(t);
		d[t]++;
	}
	queue<int> que;
	for(int i=0;i<n;i++)
		if(d[i]==0)
			que.push(i);
	while(!que.empty())
	{
		int t=que.front();que.pop();
		printf("%d\n",t);
		d[t]=INT_MAX;
		for(int i=0;i<G[t].size();i++)
		{
			d[G[t][i]]--;
			if(d[G[t][i]]==0)
				que.push(G[t][i]);
		}
	}
	return 0;
}