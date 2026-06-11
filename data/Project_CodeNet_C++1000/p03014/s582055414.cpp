#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>
#include <queue>
#include <map>
#include <set>

using namespace std;
typedef long long ll;

int main()
{
    int H, W;
    cin >> H >> W;
    vector<string> s(H);
    for (int i = 0; i < H; i++)
    {
        cin >> s[i];
    }
    vector<vector<int>> acc_h(H, vector<int>(W));
    vector<vector<int>> acc_v(H, vector<int>(W));

    for (int i = 0; i < H; i++)
    {
        for (int j = 0; j < W; j++)
        {
            if (s[i][j] != '.')
            {
                continue;
            }
            if (0 == j)
            {
                acc_h[i][j] = 1;
                continue;
            }
            acc_h[i][j] = acc_h[i][j - 1] + 1;
        }
    }

    for (int i = 0; i < H; i++)
    {
        for (int j = W - 1; j >= 0; j--)
        {
            if (acc_h[i][j] == 0)
            {
                continue;
            }
            int tempmax;
            if (j == W - 1)
            {
                tempmax = acc_h[i][j];
                continue;
            }
            if (acc_h[i][j + 1] == 0)
            {
                tempmax = acc_h[i][j];
                continue;
            }
            acc_h[i][j] = tempmax;
        }
    }

    for (int i = 0; i < W; i++)
    {
        for (int j = 0; j < H; j++)
        {
            if (s[j][i] != '.')
            {
                continue;
            }
            if (0 == j)
            {
                acc_v[j][i] = 1;
                continue;
            }
            acc_v[j][i] = acc_v[j - 1][i] + 1;
        }
    }

    for (int i = 0; i < W; i++)
    {
        for (int j = H - 1; j >= 0; j--)
        {
            if (acc_v[j][i] == 0)
            {
                continue;
            }
            int tempmax;
            if (j == H - 1)
            {
                tempmax = acc_v[j][i];
                continue;
            }
            if (acc_v[j + 1][i] == 0)
            {
                tempmax = acc_v[j][i];
                continue;
            }
            acc_v[j][i] = tempmax;
        }
    }
    int ans = -1;
    for (int i = 0; i < H; i++)
    {
        for (int j = 0; j < W; j++)
        {
            ans = max(ans, acc_v[i][j] + acc_h[i][j] - 1);
        }
    }
    cout << ans << endl;
    return 0;
}