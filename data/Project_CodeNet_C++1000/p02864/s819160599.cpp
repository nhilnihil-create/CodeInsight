#include <bits/stdc++.h>
using namespace std;

int main()
{
    int N, K;
    cin >> N >> K;

    vector<long long> H(N + 1, 0);
    for (int i = 1; i <= N; i++)
    {
        cin >> H[i];
    }

    // i-th index
    // j-th height
    // k-th change
    const long long init = 1e18;
    vector<vector<vector<long long>>> dp(
        N + 1,
        vector<vector<long long>>(
            N + 1,
            vector<long long>(
                K + 1, init)));
    dp[0][0][0] = 0;
    queue<pair<long long, long long>> q;
    q.push({0, 0});
    for (int i = 1; i <= N; i++)
    {
        set<pair<long long, long long>> tmp;
        while (!q.empty())
        {
            long long h = q.front().first;
            long long change = q.front().second;
            long long score = dp[i - 1][h][change];
            q.pop();
            dp[i][i][change] = min(dp[i][i][change], score + max(0ll, H[i] - H[h]));
            tmp.insert({i, change});
            if (change < K)
            {
                dp[i][h][change + 1] = min(dp[i][h][change + 1], score);
                tmp.insert({h, change + 1});
            }
        }
        for (pair<long long, long long> p : tmp)
        {
            q.push(p);
        }
    }
    long long ans = init;
    while (!q.empty())
    {
        ans = min(ans, dp[N][q.front().first][q.front().second]);
        q.pop();
    }
    cout << ans << endl;
}
