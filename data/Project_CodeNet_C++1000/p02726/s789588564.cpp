#include<bits/stdc++.h>
using namespace std;

using ll = long long;

int main()
{   
    int n, x, y;
    scanf("%d%d%d", &n, &x, &y);
    vector<vector<int>> adj(n+1);
    for(int i = 1; i < n; i++) {
        adj[i].push_back(i+1);
        adj[i+1].push_back(i);
    }
    adj[x].push_back(y);
    adj[y].push_back(x);
    vector<int> cnt(n);
    for(int i = 1; i <= n; i++) {
        vector<bool> visited(n+1, false);
        queue<int> q;
        q.push(i);
        vector<int> distance(n+1, 0);
        while(!q.empty()) {
            int u = q.front();
            q.pop();
            if(visited[u]) continue;
            visited[u] = true;
            cnt[distance[u]]++;
            for(int to : adj[u]) {
                if(!visited[to]) {
                    q.push(to);
                    if(distance[to] == 0) 
                        distance[to] = distance[u] + 1;
                }
            }
        }
    }
    for(int i = 1; i < n; i++ ) printf("%d\n", cnt[i]/2);
}
