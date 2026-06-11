#include <bits/stdc++.h>

using namespace std;

const int N = 1e3 + 5 , M = 12;
int cost[N] , boxes[N] , memo[N][1 << M] , n , m;
int solve (int i , int msk) {
    if (i == m) return msk == (1 << n) - 1 ? 0 : 1e9;
    int &ret = memo[i][msk];
    if (~ret) return ret;
    ret = min(solve(i + 1 , msk) , solve(i + 1 , msk | boxes[i]) + cost[i]);
    return ret;
}

int main() {
    ios::sync_with_stdio(0) , cin.tie(0) , cout.tie(0);

    cin >> n >> m;

    for (int i = 0 ;i < m ;i++) {
        int cnt;
        cin >> cost[i] >> cnt;
        while (cnt--) {
            int b;
            cin >> b;
            boxes[i] |= 1 << (b - 1);
        }
    }

    memset(memo , -1 ,sizeof memo);
    int ans = solve(0 , 0);
    if (ans == 1e9) ans = -1;
    cout << ans;
}
