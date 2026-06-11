#include<bits/stdc++.h>

using namespace std;
using ll = long long;
const int INF = 1e9;

int main()
{
    int n, m;
    cin >> n >> m;
    vector<int> cost(m), uni(m);
    for(int i = 0; i < m; i++) {
        int c;
        cin >> cost[i] >> c;
        for(int j = 0; j < c; j++) {
            int b; cin >> b; b--;
            uni[i] |= (1<<b);
        }
    }
    vector<vector<int>> dp(m + 1, vector<int>(1<<n, INF));
    dp[0][0] = 0;

    for(int i = 0; i < m; i++) {
        for(int bit = 0; bit < (1<<n); bit++) {
            dp[i + 1][bit | uni[i]] = min(dp[i][bit] + cost[i], dp[i + 1][bit | uni[i]]);
            dp[i + 1][bit] = min(dp[i][bit], dp[i + 1][bit]);
        }
    }
    cout << (dp[m][(1<<n) - 1] == INF ? -1 : dp[m][(1<<n) - 1]) << endl;
}