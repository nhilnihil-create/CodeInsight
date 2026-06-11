#include <bits/stdc++.h>

using namespace std;

int n,m;
vector <int> adj[10007];
int in[10007];
queue <int> q;

int main()
{
    cin>>n>>m;
    for(int i=0;i<m;i++)
    {
        int x,y;
        cin>>x>>y;
        in[y]++;
        adj[x].push_back(y);
    }

    for(int i=0;i<n;i++)
        if(in[i]==0)
            q.push(i);

    while(q.size()>0)
    {
        int x=q.front();
        q.pop();
        in[x]=-1;
        cout<<x<<" ";
        for(int i=0;i<adj[x].size();i++)
        {
            in[adj[x][i]]--;
            if(in[adj[x][i]]==0)
                q.push(adj[x][i]);
        }
    }
}