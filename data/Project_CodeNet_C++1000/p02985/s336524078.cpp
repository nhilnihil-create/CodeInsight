#include<bits/stdc++.h>
#define rep(i,n) for (int i = 0; i < (n); ++i)
using namespace std;
using ll = long long;
using P = pair<int, int>;

const int MOD = 1000000007;
int dist1[100005];
int dist2[100005];
bool checked[100005];
vector<int> E[100005];
int n, k;

ll dfs(int v) {
    checked[v] = true;
    ll res = k - dist1[v] - dist2[v];
    for (int u: E[v]) {
        if (checked[u]) continue;
        dist1[u]++;
        dist2[u] += dist1[v];
        dist1[v]++;
        res *= dfs(u);
        res %= MOD;
    }
    return res;
}

int main() {
    cin >> n >> k;
    rep(i, n-1) {
        int a, b;
        cin >> a >> b;
        a--; b--;
        E[a].push_back(b);
        E[b].push_back(a);
    }
    ll ans = dfs(0);
    cout << ans << endl;
    return 0;
}