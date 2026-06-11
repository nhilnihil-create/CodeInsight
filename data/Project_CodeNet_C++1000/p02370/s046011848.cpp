#include<iostream>
#include<cstdio>
#include<algorithm>
#include<list>
#include<vector>
using namespace std;
static const int MAX=100000;
vector<int> G[MAX];
int N;
list<int>out;
bool V[MAX];
void dfs(int u)
{
    V[u]=true;
    for(int i=0;i<G[u].size();i++)
    {
        int v=G[u][i];
        if(!V[v]) dfs(v);
    }
    out.push_front(u);
}
int main()
{
    int s,t,M;
    scanf("%d %d",&N,&M);
    for(int i=0;i<N;i++)
        V[i]=false;
    for(int i=0;i<M;i++)
    {
        scanf("%d %d",&s,&t);
        G[s].push_back(t);
    }
    for(int i=0;i<N;i++)
    {
        if(!V[i]) dfs(i);
    }
    for(list<int>::iterator it = out.begin();it!=out.end();it++)
        cout<< *it<<endl;
    return 0;
}

