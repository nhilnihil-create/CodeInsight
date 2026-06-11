#include <bits/stdc++.h>
using namespace std;

const int M = 1e3;
int m, n, cost[M], boxes[M], memo[M][4096], big = 5e8;

int solve(int i, int mask) {
    if (i == m) {
        if ((mask ^ ((1 << n) - 1)) == 0)
            return 0;
        return big;
    }
    int &r = memo[i][mask];
    if (r == -1)
        r = min(solve(i + 1, mask), cost[i] + solve(i + 1, mask | boxes[i]));
    return r;
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    memset(memo, -1, sizeof memo);
    cin >> n >> m;
    for (int i = 0; i < m; i++) {
        int b;
        cin >> cost[i] >> b;
        while (b--) {
            int bit;
            cin >> bit;
            bit--;
            boxes[i] |= (1 << bit);
        }
    }
    int ans = solve(0, 0);
    if (ans >= big)
        ans = -1;
    cout << ans << "\n";
}
/*

1, n
m keys
cost, boxes that it can unlock

costs 7,
unlock, 1, 4, 8

boxes
1, 2, 3, 4, 5, 6, 7, 8, 9, 10


*/