#include <bits/stdc++.h>

using namespace std;
typedef long long ll;

vector<vector<int>> to, id;
vector<int> ans;

void dfs(int v,int c=-1, int p=-1) {
    int k = 1;
    for (int i = 0; i < to[v].size(); i++) {
        int u = to[v][i];
        int ei = id[v][i];
        if (u == p) continue;
        if (c == k) k++;
        ans[ei] = k; k++;
        dfs(u, ans[ei], v);
    }
}

int main() {
    int n; cin >> n;
    to.resize(n);
    id.resize(n);
    ans.resize(n-1);
    for (int i = 0; i < n-1; i++) {
        int a, b;
        cin >> a >> b;
        a--; b--;
        to[a].push_back(b); id[a].push_back(i);
        to[b].push_back(a); id[b].push_back(i);
    }
    dfs(0);
    int mx = 0;
    for (int i = 0; i < n; i++) {
        mx = max(mx, int(to[i].size()));
    }
    cout << mx << endl;
    for (int i = 0; i < n-1; i++) {
        cout << ans[i] << endl;
    }

}
