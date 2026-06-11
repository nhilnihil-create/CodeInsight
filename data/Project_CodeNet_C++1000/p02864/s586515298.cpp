#include <bits/stdc++.h>
using namespace std;

#define watch(x) cerr << (#x) << ": " << (x) << endl
#define int long long

const int rows = 1000000000, N = 305;
int n, k, h[N];

map<int, int> dp[N][N];

void upd(int i, int j, int k, int cur) {
    if(dp[i][j].count(k)) {
        dp[i][j][k] = min(dp[i][j][k], cur);
    } else {
        dp[i][j][k] = cur;
    }
}

//[columns][used changes] -> maps[previous val] ans

int32_t main() {

    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    cin >> n >> k;

    for(int i = 0; i < n; ++i) cin >> h[i];

    dp[0][0][0] = 0;

    for(int i = 0; i < n; ++i) {
        int cur = h[i];
        for(int j = 0; j <= k && j <= i; ++j) {
            for(auto p : dp[i][j]) {
                int prev = p.first, cand = p.second;
                upd(i+1, j, cur, cand + max(0LL, cur-prev));
                if(j < k) {
                    upd(i+1, j+1, prev, cand);
                    upd(i+1, j+1, 0, cand);
                }
            }
        }
    }

    int ans = rows*N;
    for(int j = 0; j <= k; ++j) {
        for(auto p : dp[n][j]) {
            ans = min(ans, p.second);
        }
    }

    cout << ans << endl;
    
    return 0;
}
