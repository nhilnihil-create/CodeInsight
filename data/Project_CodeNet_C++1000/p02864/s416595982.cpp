#include <bits/stdc++.h>
using namespace std;

int main()
{
    int N, K;
    cin >> N >> K;

    vector<long long> H(N + 1, 0);
    set<long long> HH;
    HH.insert(0);
    for (int i = 1; i <= N; i++)
    {
        cin >> H[i];
        HH.insert(H[i]);
    }
    map<long long, long long> to_value;
    map<long long, long long> to_idx;
    long long idx = 0;
    for (long long hh : HH)
    {
        to_value[idx] = hh;
        to_idx[hh] = idx;
        idx++;
    }

    // i-th index
    // j-th height
    // k-th change
    const long long init = 1e18;
    vector<vector<vector<long long>>> dp(N + 1, vector<vector<long long>>(N + 1, vector<long long>(K + 1, init)));
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
            if (to_value[h] > H[i])
            {
                dp[i][to_idx[H[i]]][change] = min(dp[i][to_idx[H[i]]][change], score);
                tmp.insert({to_idx[H[i]], change});
                if (change < K)
                {
                    dp[i][h][change + 1] = min(dp[i][h][change + 1], score);
                    tmp.insert({h, change + 1});
                }
            }
            if (to_value[h] == H[i])
            {
                dp[i][to_idx[H[i]]][change] = min(dp[i][to_idx[H[i]]][change], score);
                tmp.insert({to_idx[H[i]], change});
            }
            if (to_value[h] < H[i])
            {
                dp[i][to_idx[H[i]]][change] = min(dp[i][to_idx[H[i]]][change], score + (H[i] - to_value[h]));
                tmp.insert({to_idx[H[i]], change});
                if (change < K)
                {
                    dp[i][h][change + 1] = min(dp[i][h][change + 1], score);
                    tmp.insert({h, change + 1});
                }
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
        if (q.front().second <= K)
        {
            ans = min(ans, dp[N][q.front().first][q.front().second]);
        }
        q.pop();
    }
    cout << ans << endl;
}
