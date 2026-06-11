#include <bits/stdc++.h>
using namespace std;

const int M = 1e3;

int val[M], cost[M], n, memo[10001];

int solve(int h) {
    if (h < 1)
        return 0;
    int &result = memo[h];

    if (result == -1) {
        result = 2e9;
        for (int i = 0; i < n; i++)
            result = min(result, solve(h - val[i]) + cost[i]);
    }
    return result;
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    memset(memo, -1, sizeof memo);
    int h;
    cin >> h >> n;
    for (int i = 0; i < n; i++)
        cin >> val[i] >> cost[i];
    cout << solve(h) << '\n';
}