#include <bits/stdc++.h>
using namespace std;

int main() {
    int n, m, a, b;
    cin >> n >> m;
    vector<int> h(n+1);
    for (int i = 1; i <= n; i++) cin >> h[i];
    vector<vector<int>> l(n+1);
    for (int i = 0; i < m; i++) {
        cin >> a >> b;
        l[a].push_back(b);
        l[b].push_back(a);
    }

    int ans = 0;
    for (int i = 1; i <= n; i++) {
        int ls = l[i].size();
        bool f = true;
        for (int j = 0; j < ls; j++) {
            int k = l[i][j];
            if (h[i] <= h[k]) {
                f = false;
                break;
            }
        }
        if (f) ans++;
    }
    cout << ans << endl;
}