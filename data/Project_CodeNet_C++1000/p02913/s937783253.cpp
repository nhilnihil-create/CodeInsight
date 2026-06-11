#include <bits/stdc++.h>
using namespace std;

void solve(int N, string S)
{
    vector<vector<int>> dp(N + 1, vector<int>(N + 1));
    for (int i = N - 1; i >= 0; i--)
    {
        for (int j = N - 1; j >= 0; j--)
        {
            if (S.at(i) == S.at(j))
                dp.at(i).at(j) = dp.at(i + 1).at(j + 1) + 1;
        }
    }
    int res = 0;
    for (int i = 0; i < N; i++)
    {
        for (int j = 0; j < N; j++)
        {
            if (j <= i)
            {
                continue;
            }
            res = max(res, min(dp.at(i).at(j), j - i));
        }
    }
    cout << res << endl;
}

int main()
{
    int N;
    cin >> N;
    string S;
    cin >> S;
    solve(N, S);
    return 0;
}
