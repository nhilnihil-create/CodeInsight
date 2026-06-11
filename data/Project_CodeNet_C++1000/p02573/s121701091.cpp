#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define pb push_back
#define MOD 1000000007
using pi = pair<int, int>;
vector<int> adj[200100];
bool visited[200100];
int dfs(int x)
{
    int ans = 0;
    if(visited[x] == false)
    {
        visited[x] = true;
        ans++;
        for(auto i:adj[x])
            ans += dfs(i);
    }
    return ans;
}
int main()
{
    int n, m;
    cin >> n >> m;
    int mx = 0;
    memset(visited, false, sizeof(visited));
    for(int i = 0; i < m; i++)
    {
        int a, b;
        cin >> a >> b;
        a--;
        b--;
        adj[a].pb(b);
        adj[b].pb(a);
    }
    for(int i = 0; i < n; i++)
    {
        if(visited[i] == 0)
            mx = max(mx, dfs(i));
    }
    cout << mx << endl;
}
