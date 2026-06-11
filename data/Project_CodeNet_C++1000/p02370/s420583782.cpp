#include <bits/stdc++.h>

using namespace std;

typedef vector <int> vi;
typedef list <int> li;

vi x[100001];
int ind[100001];
bool isvisited[100001];
li y;

void bfs(int a)
{
	queue <int> qqq;
	qqq.push(a);
	isvisited[a] = true;
	while(!qqq.empty())
	{
		int p = qqq.front();
		qqq.pop();
		y.push_back(p);
		for(int i = 0;i < x[p].size();i ++)
		{
			int xx = x[p][i];
			ind[xx] --;
			if(!isvisited[xx] && ind[xx] == 0)
			{
				isvisited[xx] = true;
				qqq.push(xx);
			}
		}
	}
}

void topo (int v)
{
	for(int i = 0;i < v;i ++)
		for(int j = 0;j < x[i].size();j ++)
			ind[x[i][j]] ++;
	for(int i = 0;i < v;i ++)
		if(!ind[i] && !isvisited[i])
			bfs(i);
	for(list <int> :: iterator it = y.begin();it != y.end();it ++)
	{
		cout << * it << endl;
	}
	//cout << endl;
}

int main()
{
	int v,e;
	int a,b;
	scanf("%d %d",&v,&e);
	for(int i = 1;i <= e;i ++)
	{
		scanf("%d %d",&a,&b);
		x[a].push_back(b);
	}
	topo (v);
	return 0;
} 