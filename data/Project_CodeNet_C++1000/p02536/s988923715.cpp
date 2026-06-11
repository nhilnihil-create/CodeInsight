/*Author : Krishna*/
#include<iostream>
#include<unordered_map>
#include<map>
#include<string>
#include<sstream>
#include<vector>
#include <cmath>
#include <stack>
#include<queue>
#include <unordered_set>
#include <algorithm>
#define ll long long
using namespace std;

vector<int>adj[100005];
vector<bool>vis(100005,false);
void dfs(int i)
{
    if(!vis[i])
    {
        vis[i]=true;
        for(auto v : adj[i])
            dfs(v);
    }
}


void solve()
{

    int n,m;
    cin>>n>>m;
    for(int i=0;i<m;i++)
    {
         int x ,y;
         cin>>x>>y;
         
         adj[x].push_back(y);
         adj[y].push_back(x);
    }
    int comp=0;
    for(int i=1;i<=n;i++)
    {
        if(!vis[i])
        {
            comp++;
            dfs(i);
        }
    }
    cout<<comp-1;


}


int main()
{
    int t;
//    cin>>t;
    t =1;
    while(t--)
    {
        solve();
    }
}

/*
 *Check for the edge cases(n=1)?
 *Is there any another approach?
 *check for data types
 *Keep on thinking
 */

