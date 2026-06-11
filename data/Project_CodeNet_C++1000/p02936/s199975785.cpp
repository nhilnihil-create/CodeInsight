#include <bits/stdc++.h>
 
using namespace std;

const int MAXV = 1000010, MAXE = 1000010;

struct edge { int u, v, weight, next; } g[MAXE];

int n, q;
int head[MAXV], idx;
bool visited[MAXV];

long long cnt[MAXV];

void dfs(int u){
    for (int j = head[u]; ~j; j = g[j].next) {
        if (!visited[g[j].v]) {
            cnt[g[j].v] += cnt[u];
            visited[g[j].v] = true;
            dfs(g[j].v);
        }
    }
}

int main(int argc, char *argv[])
{
   
    cin.tie(0);
    ios::sync_with_stdio(false);

    idx = 0;
    memset(head, -1, sizeof(head));
    memset(cnt, 0, sizeof(cnt));
    memset(visited, false, sizeof(visited));
    
    cin >> n >> q;

    for (int i = 1, u, v; i < n; i++)
    {
        cin >> u >> v;
        
        g[idx] = edge{u, v, 0, head[u]};
        head[u] = idx++;
        
        g[idx] = edge{v, u, 0, head[v]};
        head[v] = idx++;
        
    }
    
    for (int i = 0, u; i < q; i++) {
        long long delta;
        cin >> u >> delta;
        cnt[u] += delta;
    }
    visited[1] = true;
    dfs(1);

    for (int i = 1; i <= n; i++) {
        cout << cnt[i] << " ";
    }
    cout << endl;
    
    return 0;
}
