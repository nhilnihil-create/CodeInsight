#include <bits/stdc++.h>
#define rep(i, n) for (int i = 0; i < (n); ++i)
#define zero_pad(num) setfill('0') << std::right << setw(num)
using namespace std;
using ll = long long;
using ld = long double;
using P = pair<int, int>;

vector<vector<int>> to(100000);
vector<int> cnt(100000, 0);
vector<bool> vis(100000, false);
int n, k;
ll ans;
ll mod = 1000000007;
void dfs(int v, int p = -1){
    vis[v] = true;
    if(p != -1)cnt[v]--;
    for(int t : to[v]){
        if(vis[t])continue;
        int m = k - (to[v].size() + 1 - cnt[v]);
        ans *= max(m, 0);
        ans %= mod;
        cnt[v]--;
        dfs(t, v);
    }
}

int main() {
    cin >> n >> k;
    rep(i, n - 1){
        int a, b;
        cin >> a >> b;
        a--;
        b--;
        to[a].push_back(b);
        to[b].push_back(a);
    }
    rep(i, n)cnt[i] = to[i].size();
    ans = k;
    dfs(0);
    cout << ans << endl;
}