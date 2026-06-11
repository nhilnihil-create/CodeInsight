#include "bits/stdc++.h"
using namespace std;
int main()
{
		int n,x,y;
		cin>>n>>x>>y;
		vector<vector<int> >  g(n+1);

		g[x].push_back(y);
		g[y].push_back(x);

		for(int i=1;i<n;i++)
		{
			g[i].push_back(i+1);
			g[i+1].push_back(i);
		}

		vector<vector<int> > mat(n+1,vector<int>(n+1));

		function<void(int)> bfs=[&](int x)
		{
			vector<bool> vis(n+1);
			vis[x]=1;
			queue<pair<int,int> > q;

			q.push({x,0});

			while(!q.empty())
			{
				pair<int,int> t=q.front();

				q.pop();

				int nd=t.first;
				int dis=t.second;

				for(auto i:g[nd])
				{
					if(vis[i])
						continue;
					q.push({i,dis+1});
					mat[x][i]=dis+1;
					vis[i]=1;
				}

			}

		};


		for(int i=1;i<=n;i++)
		{
			bfs(i);
		}

		// for(int i=1;i<=n;i++)
		// {
		// 	for(int j=1;j<=n;j++)
		// 	{
		// 		cout<<mat[i][j]<<" ";
		// 	}
		// 	cout<<endl;
		// }


		map<int,int> mp;


	for(int i=1;i<=n;i++)
	{
		for(int j=1;j<=n;j++)
		{

			mp[mat[i][j]]++;
		}	
	}

	for(int i=1;i<n;i++)
	{
		cout<<mp[i]/2<<endl;
	}


	return 0;
}