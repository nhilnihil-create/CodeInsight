#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
 
ll N, Q;
vector<vector<ll>> G;
vector<bool> grid;
vector<ll> ans, coins;
int dfs(ll x, ll cnt){
    cnt+=coins[x];
    ans[x] = cnt;
    for(auto v : G[x]){
        if(!grid[v]) {
            grid[v] = true;
            dfs(v, cnt);
        }
    }
    return 0;
}
 
 
int main(){
    cin >> N >> Q;
    G.resize(N);
    grid.resize(N);
    ans.resize(N);
    coins.resize(N);
    for(int i = 0; i < N-1; i++){
        ll a, b; cin >> a >> b; a--; b--;
        G[a].push_back(b);
        G[b].push_back(a);
    }
    for(int i = 0; i < Q; i++){
        ll p, x; cin >> p >> x;
        coins[p-1] += x;
    }
    grid[0] = true;
    dfs(0, 0);
    for(int i = 0; i < N; i++) cout << ans[i] << " ";
    cout << endl;
}