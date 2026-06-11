#include <iostream>
#include <vector>
#include <list>
#include <queue>
using namespace std;
const int Max=10000;
vector<int>G[Max];
list<int>l;
int V,E;
int indeg[Max];
bool flag[Max];
void bfs(int u){
    queue<int>q;
    q.push(u);
    flag[u]=true;
    while(!q.empty()){
        int i=q.front();
        q.pop();
        l.push_back(i);
        for(int j=0;j<G[i].size();j++)
        {
            int v=G[i][j];
            indeg[v]--;
            if(!flag[v] && indeg[v]==0)
            {
                //l.push_back(v);
                flag[v]=true;
                q.push(v);
                
            }
        }
    }
}
void tsort(){
    for(int i=0;i<V;i++)
    {
        if(indeg[i]==0 && !flag[i])
            bfs(i);
    }
}
int main()
{
    int s,t;
    cin>>V>>E;
    for(int i=0;i<V;i++)
    {
        indeg[i]=0;
        flag[i]=false;
    }
    for(int i=0;i<E;i++)
    {
        cin>>s>>t;
        G[s].push_back(t);
        indeg[t]++;
    }
    tsort();
    for(list<int>::iterator it=l.begin();it!=l.end();it++)
        cout<<(*it)<<endl;
    return 0;
}
