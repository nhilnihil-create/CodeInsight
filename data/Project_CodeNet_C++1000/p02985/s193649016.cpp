#include<bits/stdc++.h>
using namespace std;
#define ll long long
const ll MAX = 1e5 + 5, MOD = 1e9+7;
ll n, k, ans = 1;
bool f, vis[MAX];
struct tree
{
    int to, next;
}G[2 * MAX];
int head[MAX], cnt = -1, x, y;
void add(int u, int v)
{
    cnt++;
    G[cnt].next = head[u];
    G[cnt].to = v;
    head[u] = cnt;
}
void dfs(int u, int depth, int b)
{
    vis[u] = true;
    if(depth == 1)  ans = (ans * k) % MOD;
    else if(depth == 2) ans = (ans * (k - b - 1)) % MOD;
    else ans = (ans * (k - b - 2)) % MOD;
    for(int i = head[u], b_ = 0; i != -1; i = G[i].next){
        int v = G[i].to;
        if(!vis[v]){
            dfs(v, depth + 1, b_);
            b_++;
        }
    }
}

int main()
{
    memset(head, -1, sizeof(head));
    cin >> n >> k;
    for(int i = 1; i <= n - 1; ++i){
        cin >> x >> y;
        add(x, y);
        add(y, x);
    }
    dfs(1,1,0);
    cout << ans;
    return 0;
}