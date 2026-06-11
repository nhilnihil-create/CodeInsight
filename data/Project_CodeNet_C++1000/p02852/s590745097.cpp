#include <bits/stdc++.h>
#define int long long
#define double long double
#pragma GCC optimize("O3,Ofast,no-stack-protector,unroll-loops,fast-math")
#pragma GCC target("avx,avx2,sse")
using namespace std;

signed main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    int n, k;
    string s;
    cin >> n >> k >> s;
    vector<int> dp(n + 1);
    deque<pair<int, int>> q;
    dp[n] = 0;
    q.push_back({n, 0});
    for (int i = n - 1; i >= 0; i--) {
        if (q.front().first - i > k) {
            q.pop_front();
        }
        if (s[i] == '1') {
            dp[i] = INT_MAX;
        } else {
            dp[i] = min(q.front().second + 1, (int)INT_MAX);
        }
        while (!q.empty() && q.back().second > dp[i]) {
            q.pop_back();
        }
        q.push_back({i, dp[i]});
    }
    if (dp[0] == INT_MAX) {
        cout << -1 << '\n';
        return 0;
    }
    vector<int> spisok;
    for (int i = 0; i <= n; i++) {
        if (s[i] == '0') {
            spisok.push_back(i);
        }
    }
    int ind = 0;
    int j = 0;
    while (ind != spisok.size() - 1) {
        while (dp[spisok[ind]] != dp[spisok[j]] + 1) {
            j++;
        }
        cout << spisok[j] - spisok[ind] << ' ';
        ind = j;
    }
    cout << '\n';

    fflush(stdout);
    return 0;
}
