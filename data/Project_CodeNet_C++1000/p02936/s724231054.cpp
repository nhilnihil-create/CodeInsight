
#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

const int N = 2e5 + 5;
int n, q, a, b;
int cnt[N];
vector<int> e[N];
ll res;
void dfs(int x, int par) {
    for (int i : e[x]) {
        if (i == par) continue;
        cnt[i] += cnt[x];
        dfs(i, x);
    }
}
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cin >> n >> q;
    for (int i = 0; i < n - 1; ++i) {
        cin >> a >> b;
        e[a].push_back(b);
        e[b].push_back(a);
    }
    for (int i = 0; i < q; ++i) {
        cin >> a >> b;
        cnt[a] += b;
    }
    dfs(1, 0);
    for (int i = 1; i <= n; ++i) {
        cout << cnt[i] << ' ';
    }
    cout << endl;

    return 0;
}

