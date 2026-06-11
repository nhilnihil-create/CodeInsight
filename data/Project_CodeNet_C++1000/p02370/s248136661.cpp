#include<iostream>
#include<vector>
#include<algorithm>
#include<queue>
using namespace std;
const int maxn = 10001;

vector<int> G[maxn], ans;
int indegree[maxn], vis[maxn];
int n, e;
void BFS(int s)
{
    queue<int> Q;
    Q.push(s);
    vis[s] = 1;
    while(!Q.empty())
    {
        int top = Q.front();
        ans.push_back(top);
        vis[top] = 1;
        Q.pop();
        for(int i = 0; i < G[top].size(); i++)
        {
            indegree[G[top][i]]--;
            if(indegree[G[top][i]] == 0 && vis[G[top][i]] == 0)
            {
                Q.push(G[top][i]);
            }
        }
    }
}

void topologicalSort()
{
    for(int u = 0; u < n; u++)
        if(indegree[u] == 0 && vis[u] == 0)
            BFS(u);
}

int main()
{
    cin >> n >> e;
    for(int i = 0; i < n; i++)
    {
        vis[i] = 0;
        indegree[i] = 0;
    }
    for(int i = 0; i < e; i++)
    {
        int x, y;
        cin >> x >>y;
        G[x].push_back(y);
        indegree[y]++;
    }
    topologicalSort();
    for(int i = 0; i < ans.size(); i++)
        cout << ans[i] <<endl;
    return 0;
}

