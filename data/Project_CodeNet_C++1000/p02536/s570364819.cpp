#include <bits/stdc++.h>
using namespace std;
using ll = unsigned long long int;
vector<int>adj[100002];
bool v[100002];
int tam;

void dfs(int i)
{
    if (v[i])return;
    v[i] = true;
    tam++;
    for (int j=0;j<adj[i].size();j++)
    {
         dfs(adj[i][j]);
    }
}

int main()
{
    int n, m;
    cin>>n>>m;
    set<int>node;
    for (int i=0;i<m;i++)
    {
        int a,b;cin>>a>>b;
        adj[a].push_back(b);
        adj[b].push_back(a);
        node.insert(a);
        node.insert(b);
    }
     tam = 0;
    int grafos = 0;
    for (int i=1;i<=n;i++)
    {
        if (!v[i] && node.count(i))
        {
            dfs(i);
            grafos++;
        }
    }
    //cout<<grafos<<" "<<tam<<endl;
    int ans = 0;
    ans+= (grafos - 1);
    ans += (n - tam);
    cout<<ans;

}
