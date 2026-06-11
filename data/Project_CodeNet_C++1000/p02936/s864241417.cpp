#include <iostream>
#include <vector>
using namespace std;
int N, Q;
vector<int> G[200010];
vector<int> ans(200010);
vector<bool> used(200010);

void dfs(int u) {
    used[u] = true;
    for (int v: G[u]) {
        if (used[v] == false) { 
            ans[v] += ans[u];
            dfs(v);
        }
    }
}

int main() {
    cin >> N >> Q;
    for (int i = 0; i < N-1; i++) {
        int a, b; cin >> a >> b;
        G[a-1].push_back(b-1);
        G[b-1].push_back(a-1);
    }
    for (int i = 0; i < Q; i++) {
        int p, x; cin >> p >> x;
        ans[p-1] += x;
    }
    dfs(0);
    for (int i = 0; i < N; i++) {
        cout << ans[i] << endl;
    }
}