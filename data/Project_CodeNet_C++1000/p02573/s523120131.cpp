/*input
5 3
1 2
3 4
5 1
*/

#include <bits/stdc++.h>
#define rep(i, n) for (int i = 0; i < (n); i++)
using namespace std;
using ll = long long;

const int N = 200005;
vector<int> e[N];
vector<int> c;

int dfs(int id) {
    if (c[id] != 0) return 0;
    c[id] = 1;
    int res = 1;
    rep(i, e[id].size()) {
        res += dfs(e[id][i]);
    }
    return res;
}

int main() {
    int n, m;
    cin >> n >> m;
    rep(i, m) {
        int a, b;
        cin >> a >> b;
        --a;
        --b;
        e[a].push_back(b);
        e[b].push_back(a);
    }

    c.resize(n);
    int ans = 0;
    rep(i, n) {
        if (c[i] != 0) continue;
        ans = max(ans, dfs(i));
    }
    cout << ans << endl;
}