#include<bits/stdc++.h>

using namespace std;

const int N=1e4+10;
vector<int> G[N];
bool used[N];
stack<int> order;

void add(int s,int t)
{
    G[s].push_back(t);
}

void dfs(int v)
{
    used[v]=true;
    for(int i=0;i<G[v].size();i++)
    {
        int t=G[v][i];
        if(!used[t])
        {
            dfs(t);
        }
    }
    order.push(v);
}

int main()
{
    int v,e;
    cin>>v>>e;

    for(int i=0;i<e;i++)
    {
        int s,t;
        cin>>s>>t;
        add(s,t);
    }

    for(int i=0;i<v;i++)
    {
        if(!used[i])
        {
            dfs(i);
        }
    }

    while(!order.empty())
    {
        cout<<order.top()<<endl;
        order.pop();
    }

    return 0;
}

