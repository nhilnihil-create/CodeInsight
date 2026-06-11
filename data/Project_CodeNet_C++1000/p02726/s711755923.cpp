#include <bits/stdc++.h>
using namespace std;
using ll = long long;
template <class T> inline bool chmax(T &a, T b)
{
    if (a < b)
    {
        a = b;
        return 1;
    }
    return 0;
}
template <class T> inline bool chmin(T &a, T b)
{
    if (a > b)
    {
        a = b;
        return 1;
    }
    return 0;
}

int main()
{
    int N, X, Y;
    cin >> N >> X >> Y;
    X--;
    Y--;
    vector<int> res(N, 0);
    vector<vector<int>> dp(N, vector<int>(N));
    for (int i = 0; i < N; i++)
    {
        for (int j = 0; j < N; j++)
        {
            dp[i][j] = abs(i - j);
        }
    }
    for (int i = 0; i < N; i++)
    {
        for (int j = 0; j < N; j++)
        {
            chmin(dp[i][j], dp[i][X] + dp[Y][j] + 1);
            chmin(dp[i][j], dp[i][Y] + dp[X][j] + 1);
        }
    }

    for (int i = 0; i < N; i++)
    {
        for (int j = i + 1; j < N; j++)
        {
            res[dp[i][j]]++;
        }
    }
    for (int d = 1; d < N; d++) cout << res[d] << endl;

    return 0;
}
