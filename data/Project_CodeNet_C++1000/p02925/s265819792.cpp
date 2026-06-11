#include <bits/stdc++.h>
#define rep(i, n) for(int i = 0; i < (n); i++)
using namespace std;

static const int MAXN = 1e+3;
static const int MAXV = MAXN * (MAXN-1) / 2;
int mat[MAXN][MAXN], dp[MAXV];
vector<int> adj[MAXV];
bool visited[MAXV], calculated[MAXV];

// max length of path from s
int dfs(int u){
    if(visited[u]){
        if(!calculated[u]) return -1;
        return dp[u];
    }
    visited[u] = true;
    dp[u] = 1;
    for(int v : adj[u]){
        int res = dfs(v);
        if(res == -1) return -1;
        dp[u] = max(dp[u], res + 1);
    }
    calculated[u] = true;
    return dp[u];
}

int main(){
    int n;
    cin >> n;
    int cnt = 0, v = n * (n-1) / 2;
    rep(i, n) for(int j = i+1; j < n; j++){
        mat[i][j] = mat[j][i] = cnt;
        cnt++;
    }
    int a, prev_a;
    rep(i, n){
        scanf("%d", &prev_a);
        prev_a--;
        rep(_, n-2){
            scanf("%d", &a);
            a--;
            adj[mat[i][prev_a]].push_back(mat[i][a]);
            prev_a = a;
        }
    }
    rep(i, v){
        visited[i] = calculated[i] = false;
        dp[i] = 0;
    }
    int ans = 0;
    rep(i, v){
        int res = dfs(i);
        if(res == -1){
            ans = -1;
            break;
        }
        ans = max(ans, res);
    }
    cout << ans << "\n";
}