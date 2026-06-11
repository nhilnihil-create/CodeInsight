#include <iostream>
#include <cstdio>
#include <vector>
#include <queue>
#include <cstring>
using namespace std;
int n,m,st,t,s[100005][3];
vector<int> g[100005];
int main()
{
	memset(s,63,sizeof(s));
	scanf("%d%d",&n,&m);
	for(int i=1;i<=m;i++)
	{
		int u,v;
		scanf("%d%d",&u,&v);
		g[u].push_back(v);
	}
	scanf("%d%d",&st,&t);
	queue<int> q;
	q.push(st);
	s[st][0]=0;
	while(!q.empty())
	{
		int u=q.front();
//		cout<<u<<"  ";
		q.pop();
		for(int i=0;i<g[u].size();i++)
		{
			int v=g[u][i],yes=0;
//			cout<<v;
			if(s[u][0]+1<s[v][1])
			{
				yes=1;
				s[v][1]=s[u][0]+1;
			}
			if(s[u][1]+1<s[v][2])
			{
				yes=1;
				s[v][2]=s[u][1]+1;
			}
			if(s[u][2]+1<s[v][0])
			{
				yes=1;
				s[v][0]=s[u][2]+1;
			}
			if(yes==1)
			{
//				cout<<".";
				q.push(v);
			}
//			cout<<' ';
		}
//		cout<<endl;
	}
//	for(int i=1;i<=n;i++)
//	{
//		cout<<s[i][0]<<' '<<s[i][1]<<' '<<s[i][2]<<endl;
//	}
	if(s[t][0]!=s[0][0])
	{
		printf("%d",s[t][0]/3);
	}
	else
	{
		printf("-1");
	}
	return 0;
}
