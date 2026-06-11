
#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef pair<int, int> ii;

const int N = 13;
const int M = 1001;
int n, m, a, b, c;
ii p[M];
int dp[1 << N];

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cin >> n >> m;
    for (int i = 0; i < m; ++i) {
        cin >> a >> b;
        int mask = 0;
        for (int j = 0; j < b; ++j) {
            cin >> c;
            mask |= (1 << (c - 1));
        }
        p[i] = {a, mask};
    }
    memset(dp, 255, sizeof dp);
    dp[0] = 0;

    for (int ms = 0; ms < (1 << n) - 1; ++ms) {
        if (dp[ms] != -1) {
            for (int i = 0; i < m; ++i) {
                auto pa = p[i];
                int cost = pa.first;
                int mm = pa.second;
                int nm = mm | ms;
                if (dp[nm] == -1 || dp[nm] > dp[ms] + cost) {
                    dp[nm] = dp[ms] + cost;
                }
            }
        }
    }

    if (dp[(1 << n) - 1] == -1) {
        cout << -1 << endl;
    } else {
        cout << dp[(1 << n) - 1] << endl;
    }

    return 0;
}

