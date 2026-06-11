#include<iostream>
#include <bits/stdc++.h>
#define ll long long
#define IO ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
using namespace std;
int n, m, dis[100009][4], inf=2e9;
vector<int> v[100009];
void BFS(int s)
{
    queue<pair<int,int> > q ;
    q.push({s,0});
    for(int i=1; i<=n; i++)
        dis[i][0]=dis[i][1]=dis[i][2]=inf;
    dis[s][0] = 0;
    while(!q.empty())
    {
        int node=q.front().first, d=q.front().second;
        q.pop();
        for(auto i : v[node])
            if(dis[i][(d+1)%3]>dis[node][d]+1)
            {
                dis[i][(d+1)%3]=dis[node][d]+1;
                q.push({i,(d+1)%3});
            }
    }
}
int main()
{
    IO
    cin>>n>>m;
    for(int i=1; i<=m; i++)
    {
        int x, y ;
        cin>>x>>y;
        v[x].push_back(y);
    }
    int s, t ;
    cin>>s>>t;
    BFS(s);
    if(dis[t][0]>=inf)
        dis[t][0]=-3;
    cout<<dis[t][0]/3;
}
