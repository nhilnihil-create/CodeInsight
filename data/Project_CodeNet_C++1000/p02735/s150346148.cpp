#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using P = pair<int, int>;
const int INF = 1001001001;
const ll LINF = 1LL << 60;
const int MOD = 1'000'000'007;

template <typename T>
void print(const T &v)
{
    for (int i = 0; i < v.size(); i++)
    {
        if (i)
            cout << ' ';
        cout << v[i];
    }
    cout << endl;
}

template <class T>
inline bool chmin(T &a, T b)
{
    if (a > b)
    {
        a = b;
        return true;
    }
    return false;
}

template <class T>
inline bool chmax(T &a, T b)
{
    if (a < b)
    {
        a = b;
        return true;
    }
    return false;
}

// const int MAX = 1010;

int dp[110][110] = {INF};

int main()
{
    int h, w;
    cin >> h >> w;
    vector<vector<int>> g(h, vector<int>(w, 0));

    for (int i = 0; i < h; i++)
    {
        string line;
        cin >> line;
        for (int j = 0; j < w; j++)
        {
            if (line[j] == '.')
            {
                g[i][j] = 0;
            }
            else
            {
                g[i][j] = 1;
            }
        }
    }
    dp[0][0] = 0;
    for (int j = 1; j < w; j++)
    {
        if (g[0][j] && !g[0][j - 1])
        {
            dp[0][j] = dp[0][j - 1] + 1;
        }
        else
        {
            dp[0][j] = dp[0][j - 1];
        }
    }
    for (int i = 1; i < h; i++)
    {
        if (g[i][0] && !g[i - 1][0])
        {
            dp[i][0] = dp[i - 1][0] + 1;
        }
        else
        {
            dp[i][0] = dp[i - 1][0];
        }
    }

    for (int i = 1; i < h; i++)
    {
        for (int j = 1; j < w; j++)
        {
            // マスが白の場合
            if (!g[i][j])
            {
                dp[i][j] = min(dp[i - 1][j], dp[i][j - 1]);
            }
            else
            {
                dp[i][j] = min(dp[i - 1][j] + (g[i - 1][j] + g[i][j]) % 2, dp[i][j - 1] + (g[i][j - 1] + g[i][j]) % 2);
            }
        }
    }
    // for (int i = 0; i < 3; i++)
    // {
    //     for (int j = 0; j < 3; j++)
    //     {
    //         cout << dp[i][j];
    //     }
    //     cout << endl;
    // }
    if (g[0][0])
    {
        cout << dp[h - 1][w - 1] + 1 << endl;
    }
    else
    {
        cout << dp[h - 1][w - 1] << endl;
    }
    return 0;
}