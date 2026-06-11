#include <bits/stdc++.h>

using namespace std;
const int maxn=1e5+5;

vector<int> ady[maxn];
int mk[maxn];

int cont=0;

void dfs(int node)
{
    mk[node]=1;

    for(int x:ady[node])
    {
        if(!mk[x])
        {
            dfs(x);
        }       
    }  
}

int main()
{
    int n,m;
    cin>>n>>m;
    
    for(int i=0;i<m;i++)
    {
        int a,b;cin>>a>>b;

        ady[a].push_back(b);
        ady[b].push_back(a);
    }

    for(int i=1;i<=n;i++)
    {
        if(!mk[i])
        {
            dfs(i);
            cont++;
        } 
    }
    cout<<cont-1<<'\n';
}