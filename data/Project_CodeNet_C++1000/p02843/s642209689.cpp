#include <bits/stdc++.h>

using namespace std;
using ll = long long;
using Graph = vector<vector<int>>;
using pint = pair<int, int>;
int dx[4] = {1, 0, -1, 0};
int dy[4] = {0, 1, 0, -1};
const int MOD = 1000000009;
const long long INF = 1LL << 60;

int main() {
    int X;
    cin >> X;
    vector<int> items {100, 101, 102, 103, 104, 105};
    vector<int> dp(X+1, 0);
    dp[0] = 1;
    for (int i = 0; i <= X; ++i) {
        for (int j = 0; j < 6; ++j) {
            int to = i + items[j];
            dp[to] |= dp[i];
        }
    }
    cout << dp[X] << endl;
    return 0;
}