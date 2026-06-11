#include <bits/stdc++.h>
#define initrand mt19937 mt_rand(time(0));
#define rand mt_rand()

using namespace std;
#define mid(l, u) ((l+u)/2)
#define lchild(i) (i*2 + 1)
#define rchild(i) (i*2 + 2)
#define INF 10000000000000000
#define int long long
signed main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int n;
    cin>>n;
    int k[n+1];
    for(int i = 1;i<=n;i++) k[i] = 0;
    vector<int> adj[n+1];
    for(int i = 1;i<n;i++){
        int u, v;
        cin>>u>>v;
        if(u>v) swap(u, v);
        k[v] = max(k[v], u);
        adj[u].push_back(v);
        adj[v].push_back(u);
    }
    for(int i = 1;i<=n;i++) sort(adj[i].begin(), adj[i].end());
    int dp[n+1];
    dp[0] = 0;
    int ans = 0;
    for(int i = 1;i<=n;i++){
        dp[i] = dp[i-1] + (i - k[i]);
        int ind = 1;
        int sum = 0;
        for(;ind<adj[i].size() && adj[i][ind]<i;ind++){
            dp[i] -= adj[i][ind-1];
            //dp[i] -= sum;
        }
        ans += dp[i];
    }
    cout<<ans<<endl;
    return 0;
}