#include <iostream>
#include<vector>
#include<queue>
#include<list>
#include<algorithm>
using namespace std;
static const int MAX=100000;
static const int INFTY=(1<<29);
vector<int>G[MAX];
list<int>out;
bool V[MAX];
int N;
int indeg[MAX];
void bfs(int u)
{
    queue<int>q;
    q.push(u);
    V[u]=true;
    while(!q.empty())
    {
        int v=q.front();
        q.pop();
        out.push_back(v);
        for(int i=0; i<G[v].size(); i++)
        {
            int u=G[v][i];
            indeg[u]--;
            if(indeg[u]==0&&!V[u])
            {
                q.push(u);
                V[u]=true;
            }
        }
    }
}
void tsort()
{
    for(int i=0; i<N; i++)
    {
        V[i]=false;
        indeg[i]=0;
    }
    for(int i=0; i<N; i++)
    {
        for(int j=0; j<G[i].size(); j++)
        {
            int v=G[i][j];
            indeg[v]++;
        }
    }
    for(int u=0; u<N; u++)
        if(indeg[u]==0&&!V[u])bfs(u);
    for(list<int>::iterator it=out.begin(); it!=out.end(); it++)
    {
        cout<<*it<<endl;
    }
}
int main()
{
    int e,v,c;
    cin>>N>>e;
    for(int i=0; i<e; i++)
    {
        cin>>v>>c;
        G[v].push_back(c);
    }
    tsort();
    return 0;

}