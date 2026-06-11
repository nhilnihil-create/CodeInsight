#include <iostream>
#include <vector>
#include <algorithm>
#include <numeric>
#include <functional>
#include <queue>
#include <stack>
#include <bitset>
#include <set>
#include <chrono>
#include <string>
#include <assert.h>

using namespace std;

#define endl '\n'

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int n; cin >> n;

    vector<vector<int>> mat(n, vector<int>(n));

    int t = 0;

    for (int i = 0; i < n; ++i)
        for (int j = 0; j < i; ++j) {
            mat[i][j] = mat[j][i] = t++;
        }

    vector<vector<int>> adj(t);
    vector<int> deg(t);

    for (int i = 0; i < n; ++i) {
        int l; cin >> l; l--;

        for (int j = 0; j < n - 2; ++j) {
            int u; cin >> u;
            u--;
            adj[mat[i][l]].push_back(mat[i][u]);
            deg[mat[i][u]]++;
            l = u;
        }
    }

    vector<int> dp(t);

    vector<int> q;

    for (int i = 0; i < t; ++i) {
        if (deg[i] == 0) {
            q.push_back(i);
            dp[i] = 1;
        }
    }
    int ans = 0;

    for (int i = 0; i < q.size(); ++i) {
        int u = q[i];
        ans = max(ans, dp[u]);

        for (auto v : adj[u]) {
            if (--deg[v] == 0) {
                dp[v] = max(dp[v], dp[u] + 1);
                q.push_back(v);
            }
        }
    }

    if (q.size() == t) {
        cout << ans << endl;
    } else {
        cout << -1 << endl;
    }

    return 0;
}