#include <iostream>
#include <queue>
#include <vector>
#include <algorithm>

static const int MAX = 10000;

using namespace std;
int V,E;
vector<int> G[MAX];
vector<int> ans;
bool used[MAX]; //訪問済みかどうか
int indeg[MAX]; //各点の入次数

void bfs(int s){
    queue<int> q;
    q.push(s);
    used[s]=true;
    while(!q.empty())
    {
        int u=q.front(); q.pop();
        ans.push_back(u);
        for(int i=0;i<G[u].size();i++)
        {
            int k = G[u][i];
            indeg[k]--;
            if(indeg[k]==0 && !used[k])
            {
                used[k]=true;
                q.push(k);
            }
        }
    }
}

void topological()
{
    for(int u=0;u<V;u++)
    {
        if(indeg[u]==0 && !used[u])
        {
            bfs(u);
        }
    }
}

int main(){
    cin>>V>>E;
    fill(indeg,indeg+MAX,0);
    fill(used,used+MAX,0); //訪問済み=true
    for(int i=0;i<E;i++){
        int s,t;
        cin>>s>>t;
        G[s].push_back(t);
        indeg[t]++;
    }
    topological();
    for(int i=0;i<V;i++)
    {
        cout<<ans[i]<<"\n";
    }

}

