#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for (int i = 0; i < (n); i++)
typedef long long ll;

vector<int> tree[200005];
vector<int> ans;

void dfs(int p, int u=-1) {
    for (int t : tree[p]) {
        if (t == u) continue;
        ans[t] += ans[p];
        dfs(t, p);
    }
}

int main() {
    int n, q;
    cin >> n >> q;
    rep(i, n-1) {
        int a, b;
        cin >> a >> b;
        a--; b--;
        tree[a].push_back(b);
        tree[b].push_back(a);
    }
    ans.resize(n);
    rep(i, q) {
        int p, x;
        cin >> p >> x;
        p--;
        ans[p] += x;
    }
    dfs(0);
    rep(i, n) cout << ans[i] << endl;
}