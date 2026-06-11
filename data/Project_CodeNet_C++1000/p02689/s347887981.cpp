#include <bits/stdc++.h>
#define ll long long
#define ar array
#define AC ios_base::sync_with_stdio(0); cin.tie(NULL);
using namespace std;
const int M = 1e9+7;
const int N = 1e5;
int height[N+5];
vector<int> adj[N+5];
bool bad[N+5];

int main(){
    int n, m;
    cin>>n>>m;
    for(int i=1; i<=n; i++){
        cin>>height[i];
    }

    for(int i=0; i<m; i++){
        int x, y;
        cin>>x>>y;
        adj[x].push_back(y);
        adj[y].push_back(x);
    }
    int ans = 0;

    for(int i=1; i<=n; i++){
        int tot = 0;
        for(int j=0; j<adj[i].size(); j++){
            if(height[i] > height[adj[i][j]])
                tot++;
        }
        if(tot==adj[i].size())
            ans++;
    }
    cout<<ans<<endl;
}