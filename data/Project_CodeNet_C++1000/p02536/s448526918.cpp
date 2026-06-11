#include<bits/stdc++.h>
using namespace std;
typedef long long ll;


void dfs(vector<int> adj[],int sv,bool * visited)
{
	visited[sv]=true;
	for(int i=0;i<adj[sv].size();i++)
	{
		if(visited[adj[sv][i]]==false)
		{
			dfs(adj,adj[sv][i],visited);
		}
	}
}
int cnt(vector<int>adj[],int n)
{
	bool * visited=new bool[n];
	for(int i=0;i<n;i++)
	{
		visited[i]=false;
	}
	
	int ct=0;
	for(int i=0;i<n;i++)
	{
		if(visited[i]==false)
		{
			dfs(adj,i,visited);
			ct++;
		}
		
	}
	return ct;
}
int main()
{
	int n;
	cin>>n;
	int m;
	cin>>m;
	
	vector<int> adj[n];

	
	for(int i=0;i<m;i++)
	{
		int x,y;
		cin>>x>>y;
		adj[x-1].push_back(y-1);
		adj[y-1].push_back(x-1);
	
	}
	
	int ct=cnt(adj,n);
	cout<<ct-1;
}
