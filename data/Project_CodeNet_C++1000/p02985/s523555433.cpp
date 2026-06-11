#include<bits/stdc++.h>
using namespace std;

#define LL long long
const int mod = 1e9 + 7;
LL ans = 1LL, n, k, x, y;
vector<int> g[100005];

void dfs(int v, int par, int l, LL x) {
    if(x < 0) {ans = 0; return;}
    ans *= x; ans %= mod;

    if(l < 2) {
        int cnt = 1;
        for(int u : g[v]) {
            if(u == par) continue;
            dfs(u, v, l+1, x-cnt);
            cnt++;
        }
    }
    else {
        x = k - 2;
        int cnt = 0;
        for(int u : g[v]) {
            if(u == par) continue;
            dfs(u, v, l+1, x-cnt);
            cnt++;
        }
    }
}

int main() {
    ios::sync_with_stdio(0), cin.tie(0);
    
    cin >> n >> k;
    for(int i = 0; i < n-1; i++) {
        cin >> x >> y;
        g[x].push_back(y);
        g[y].push_back(x);
    }    
    dfs(1, 0, 1, k);
    cout << ans;
}