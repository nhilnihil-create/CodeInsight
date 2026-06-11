#include <bits/stdc++.h>
using namespace std;

int main()
{
    int H, W;
    cin >> H >> W;
    vector<string> s(H);
    for (int r = 0; r < H; r++)
    {
        cin >> s.at(r);
    }

    vector<vector<int>> dp(H, vector<int>(W, 0));
    if (s.at(0).at(0) == '#')
    {
        dp.at(0).at(0) = 1;
    }
    for (int r = 1; r < H; r++)
    {
        if (s.at(r).at(0) == '#')
        {
            if (s.at(r - 1).at(0) == '#')
                dp.at(r).at(0) = dp.at(r - 1).at(0);
            else
                dp.at(r).at(0) = dp.at(r - 1).at(0) + 1;
        }
        else
        {
            dp.at(r).at(0) = dp.at(r - 1).at(0);
        }
    }
    for (int c = 1; c < W; c++)
    {
        if (s.at(0).at(c) == '#')
        {
            if (s.at(0).at(c - 1) == '#')
                dp.at(0).at(c) = dp.at(0).at(c - 1);
            else
                dp.at(0).at(c) = dp.at(0).at(c - 1) + 1;
        }
        else
        {
            dp.at(0).at(c) = dp.at(0).at(c - 1);
        }
    }
    for (int r = 1; r < H; r++)
    {
        for (int c = 1; c < W; c++)
        {
            int cost_d, cost_r;
            if (s.at(r).at(c) == '#')
            {
                if (s.at(r - 1).at(c) == '#')
                    cost_d = dp.at(r - 1).at(c);
                else
                    cost_d = dp.at(r - 1).at(c) + 1;
                if (s.at(r).at(c - 1) == '#')
                    cost_r = dp.at(r).at(c - 1);
                else
                    cost_r = dp.at(r).at(c - 1) + 1;
            }
            else
            {
                cost_d = dp.at(r - 1).at(c);
                cost_r = dp.at(r).at(c - 1);
            }
            dp.at(r).at(c) = min(cost_d, cost_r);
        }
    }
    cout << dp.at(H - 1).at(W - 1) << endl;
}