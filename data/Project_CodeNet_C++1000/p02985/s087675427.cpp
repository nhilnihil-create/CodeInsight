#include <iostream>
#include <vector>

using namespace std;
constexpr int64_t MOD = 1'000'000'007;
int64_t N, K, ans;

void dfs(vector<vector<int>> &g, int v, int p = -1) {
    if(p == -1) {
        for(int i=0; i<g[v].size(); i++) {
            ans *= K-1-i;
            ans %= MOD;
            dfs(g, g[v][i], v);
        }
    } else {
        for(int i=0; i<g[v].size(); i++) {
            if(g[v][i] == p) continue;
            dfs(g, g[v][i], v);
        }
        for(int i=0; i<g[v].size()-1; i++) {
            ans *= K-2-i;
            ans %= MOD;
        }
    }
    return;
}

int main(void) {
    cin >> N >> K;
    ans = K;
    vector< vector<int> > g(N);
    while(--N) {
        int a, b;
        cin >> a >> b;
        --a; --b;
        g[a].push_back(b);
        g[b].push_back(a);
    }

    dfs(g, 0);

    cout << ans << endl;
    return 0;
}
