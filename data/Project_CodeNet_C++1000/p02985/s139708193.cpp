#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

const int MAX_N = 1e5;
const int MOD = 1e9 + 7;
int N, K;
vector<vector<int> > tree(MAX_N + 1);
vector<bool> visited(MAX_N + 1, false);
vector<int> memo(MAX_N+1, 0);

int dfs(int frm, int obj) {
    ll ret = 1;
    memo[obj]++;
    ret *= K - memo[obj] - memo[frm];
    ret %= MOD;
    for (int x : tree[obj]) {
        if (!visited[x]) {
            visited[x] = true;
            ret *= dfs(obj, x);
            ret %= MOD;
            memo[obj]++;
        }
    }
    return ret;
}

int main() {
    cin >> N >> K;
    for (int i = 0; i < N-1; i++) {
        int a, b; cin >> a >> b;
        tree[a].push_back(b);
        tree[b].push_back(a);
    }
    ll ans = 1;
    visited[1] = true;
    memo[1] = -1;
    ans *= dfs(0, 1);
    cout << ans << endl;
}
