#include <bits/stdc++.h>
#include <iostream>
typedef long long ll;
#define rep(i,a,b) for(ll i =a ;i <= b;i++)
#define per(i,a,b) for(ll i =a ;i >= b;i--)
using namespace std;
typedef vector<int> vi;
typedef vector<vector<int>> vvi;

vvi graph;
vi h;
int n,m;
vector<bool> tallest,visited;

void dfs(int index)
{
	//cout<<index<<" \n";
	if(visited[index])
		return;
	visited[index] = true;
	for(auto edge: graph[index])
	{
		if(h[edge] >= h[index]){
			//cout<<index<<" Rejected\n";
			tallest[index] = false;
			break;
		}
	}
	for(auto edge: graph[index])
		dfs(edge);
	

}

int main(int argc, char const *argv[])
{
	//ifstream cin("input.txt");
	int x,y;
	cin>>n>>m;
	h = vi(n);
	graph = vvi(n);
	tallest = vector<bool>(n,true);
	visited = vector<bool>(n,false);
	rep(i, 0, n-1)
		cin>>h[i];

	rep(i, 0, m-1)
	{
		cin>>x>>y;
		x--;
		y--;
		graph[x].push_back(y);
		graph[y].push_back(x);
	}
	rep(i, 0, n -1)
		if(!visited[i])
			dfs(i);

	cout<<count(tallest.begin(), tallest.end(), true);
	
}