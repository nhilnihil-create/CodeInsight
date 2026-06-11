#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
typedef long long LL;
const int N = 2e5;
vector<int> adj[N+1];
int p[N+1];
void dfs(int u, int prev)
{
    p[u] = prev;
    for(const int& v : adj[u])
        if(v != prev)
            dfs(v,u);
}
int main()
{
    int n; cin >> n;
    for(int i = 0; i < n-1; i++)
    {
        int u, v; cin >> u >> v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }
    dfs(1,-1);
    LL ans = n; // for 1
    for(LL s = 2; s <= n; s++)
        if(p[s] < s)
            ans += (s-p[s])*(n-s+1);
        else
            ans += s*(p[s]-s);
    cout<<ans<<endl;
    return 0;
}