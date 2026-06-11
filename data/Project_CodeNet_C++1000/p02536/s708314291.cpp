#include <bits/stdc++.h>
using namespace std;


void dfs(int node, vector < vector<int> >&arr, char c[])
{
	if (c[node]=='g')
	{
		return;
	}
	c[node]='g';
	for (int i=0; i<arr[node].size(); i++)
	{
		if (c[arr[node][i]]=='w')
		{
			dfs(arr[node][i], arr, c);
		}
	}
}


int main()
{
	/*
	 #ifndef ONLINE_JUDGE
    // for getting input from input.txt
    freopen("input.txt", "r", stdin);
    //for writing output to output.txt
    freopen("output.txt", "w", stdout);
    #endif
    */

	int n,m;
	cin>>n>>m;
	vector< vector <int> >arr(n+1);
	int a,b;
	for (int i=0; i<m; i++)
	{
		cin>>a>>b;
		arr[a].push_back(b);
		arr[b].push_back(a);

	}
	char* c=new char[n+1];
	for (int i=0; i<=n; i++)
	{
		c[i]='w';
	}
	int ans=0;
	for (int i=1; i<=n; i++)
	{
		if (c[i]=='w')
		{

			dfs(i, arr, c);
			if (i==1)
			{
				continue;
			}
			ans++;
		}

	}
	cout<<ans<<endl;


	return 0;
}
