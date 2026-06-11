#include <bits/stdc++.h>
using namespace std;
 
#define ll long long
#define ii pair<int, int>
#define dd pair<double, double>
#define pb(i) push_back(i)


int dir1[4] = {0, 0, 1, -1};
int dir2[4] = {1, -1, 0, 0};
 
int n;
vector< set<ii> > p;
vector<vector<int> > adj;
vector<bool> visited;
vector<int> dist;
 
void bfs(int u){
    int ind = u;
    int i, j;
 
    fill(visited.begin(), visited.end(), false);
    visited[u] = true;
 
    fill(dist.begin(), dist.end(), -1);
    dist[u] = 0;
 
    queue<int> q;
    q.push(u);
    while(!q.empty()){
        u = q.front();
        q.pop();
 
        for(i = 0; i < adj[u].size(); i++)
        {
            int v = adj[u][i];
            if(!visited[v])
            {
                visited[v] = true;
                dist[v] = dist[u] + 1;
                q.push(v);
            }
        }
    }
 
    for(int i = 1; i <= n; i++)
        if(dist[i] != -1)
        {
            int a = ind, b = i;
            if(a > b)
                swap(a, b);
            p[dist[i]].insert(ii(a, b));
        }
}
 
int main(){
    int i, j;
 
    int x, y;
    cin >> n >> x >> y;
 
    adj.resize(n+5);
    for(i = 1; i < n; i++){
        adj[i].pb(i+1); 
        adj[i+1].pb(i);
    }
 
    adj[x].pb(y);
    adj[y].pb(x);
 
    p.resize(n+5);
    dist.resize(n+5);
    visited.resize(n+5);
    for(i = 1; i <= n; i++)
        bfs(i);
    
 
    for(i = 1; i < n; i++)
        cout << p[i].size() << '\n';
    
 
}