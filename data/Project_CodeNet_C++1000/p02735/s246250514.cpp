#include <iostream>
#include <iomanip>
#include <limits>
#include <string>
#include <vector>
#include <algorithm>
#include <stdio.h>
#include <cmath>
#include <functional>

#define big ((long long)(1e9) + 7)

using namespace std;

typedef unsigned long long ull;
typedef long long ll;

#define DBG(x) cerr << #x << ": " << (x) << " (L" << __LINE__ << ")" << endl;

void setmin(int &a, int b)
{
    if (a > b)
        a = b;
}

int main()
{
    int INF = 1000000;
    int h, w;
    cin >> h >> w;
    vector<vector<char> > s(h, vector<char>(w));
    for (int i = 0; i < h; i++)
    {
        for (int j = 0; j < w; j++)
        {
            cin >> s[i][j];
        }
    }

    vector<vector<int> > dp(h + 1, vector<int>(w + 1, INF));
    dp[1][1] = s[0][0] == '.' ? 0 : 1;
    int dr[] = {-1, 0};
    int dc[] = {0, -1};
    for (int i = 0; i < h; i++)
    {
        for (int j = 0; j < w; j++)
        {
            for (int dir = 0; dir < 2; dir++)
            {
                int pr = i + dr[dir];
                int pc = j + dc[dir];
                if (dp[pr + 1][pc + 1] == INF)
                    continue;
                int changed = s[i][j] != s[pr][pc];
                setmin(dp[i + 1][j + 1], dp[pr + 1][pc + 1] + changed);
            }
        }
    }
    DBG(dp[h][w]);
    cout << (dp[h][w] + 1) / 2 << endl;
}
