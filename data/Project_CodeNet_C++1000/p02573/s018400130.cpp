#include <bits/stdc++.h>

using namespace std;

#define ll long long
#define pb push_back
const int MAX (2e5+2);
#define debug2(x,y) cout << x << " " << y << "\n"

ll const mod  = 1e9+7;
vector<int>visited(MAX,0);
vector<vector<int>> adj(MAX);

int main() {
    int n,m,x,y,ans=0;
    cin >> n >> m;
    for(int i = 0; i < m ; i++){
        cin >> x >> y;
        adj[x].pb(y);
        adj[y].pb(x);
    }
    for(int i = 1; i <= n; i++){
        if(visited[i] == 1)
            continue;
        visited[i] = 1;
        queue<int>q;
        q.push(i);
        int cnt = 0;

        while(!q.empty()){
            int x = q.front();
            q.pop();
            cnt++;
            for(auto v : adj[x]){
                if(!visited[v]){
                    q.push(v);
                    visited[v] = 1;
                    // cout << v << " ";
                }
            }
        }
        ans = max(ans,cnt);
    }
    // for(int i = 1; i <= n; i++){
    //     cout << i << " -> ";
    //     for(auto j : adj[i]){
    //         cout << j << " ";
    //     }cout << "\n";
    // }
    cout << ans << "\n";
}




