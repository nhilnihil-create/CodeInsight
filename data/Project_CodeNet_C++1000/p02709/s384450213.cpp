#include <bits/stdc++.h>
using namespace std;

int main()
{
    size_t N;
    cin >> N;

    vector<long long> A(N);
    for (long long &a : A)
    {
        cin >> a;
    }

    priority_queue<pair<long long, size_t>> q;
    for (size_t i = 0; i < N; i++)
    {
        q.push(make_pair(A[i], i));
    }

    vector<vector<long long>> dp(N + 1, vector<long long>(N + 1, 0));
    for (size_t i = 0; !q.empty(); i++)
    {
        for (size_t j = 0; j <= i; j++)
        {
            dp[j + 1][i - j] = max(dp[j + 1][i - j], dp[j][i - j] + q.top().first * abs((long long)(q.top().second - j)));
            dp[j][i - j + 1] = max(dp[j][i - j + 1], dp[j][i - j] + q.top().first * abs((long long)(((N - 1) - (i - j)) - q.top().second)));
        }
        q.pop();
    }

    long long ans = 0;
    for (size_t i = 0; i <= N; i++)
    {
        ans = max(ans, dp[i][N - i]);
    }
    cout << ans << endl;
}
