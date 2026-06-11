#include <bits/stdc++.h>

using namespace std;

int solveDp(vector<pair<int, int>> a, int t) {
    int n = a.size();
    sort(a.begin(), a.end());
    vector<vector<int>> mem(n, vector<int>(t, -1));
    function<int(int, int)> dp;
    dp = [&] (int i, int j) {
        if (i < 0) {
            return 0;
        }
        auto &ans = mem[i][j];
        if (ans == -1) {
            ans = dp(i-1, j);
            auto cur = a[i];
            if (cur.first <= j) {
                ans = max(ans, dp(i-1, j - cur.first) + cur.second);
            }
        }
        return ans;
    };
    int ans = 0;
    for (int i = 0; i < n; i++) {
        ans = max(ans, dp(i-1, t-1) + a[i].second);
    }
    return ans;
}

int main() {
    ios_base::sync_with_stdio(false); cin.tie(0);
    int n, t;
    cin >> n >> t;
    vector<pair<int, int>> a(n);
    for (int i = 0; i < n; i++) {
        cin >> a[i].first >> a[i].second;
    }
    auto ans = solveDp(a, t);
    cout << ans << endl;
}
