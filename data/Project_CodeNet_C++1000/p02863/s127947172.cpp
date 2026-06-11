#include <bits/stdc++.h>
using namespace std;

int main()
{
    int n, t;
    cin >> n >> t;
    vector<pair<int, int>> ab(n, pair<int, int>());
    for (int i = 0; i < n; i++)
    {
        cin >> ab.at(i).first >> ab.at(i).second;
    }
    sort(ab.begin(), ab.end());

    vector<vector<int>> dp(n + 1, vector<int>(t, 0));
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < t; j++)
        {
            int ai = ab.at(i).first, bi = ab.at(i).second;
            if (j - ai >= 0)
            {
                dp.at(i + 1).at(j) = max(dp.at(i).at(j - ai) + bi, dp.at(i).at(j));
            }
            else
            {
                dp.at(i + 1).at(j) = dp.at(i).at(j);
            }
        }
    }

    vector<int> max_bi(n + 1, 0);
    int tmp_max = 0;
    for (int i = n - 1; i >= 0; i--)
    {
        tmp_max = max(tmp_max, ab.at(i).second);
        max_bi.at(i) = tmp_max;
    }

    int res = 0;
    for (int i = 0; i < n; i++)
    {
        res = max(res, dp.at(i).at(t - 1) + max_bi.at(i));
    }
    cout << res << endl;
}