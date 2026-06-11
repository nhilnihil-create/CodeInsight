#include <bits/stdc++.h>
#define rep(i, n) for (int i = 0; i < (n); ++i)
using namespace std;
using ll = int64_t;
using pint = pair<int, int>;

int main()
{
    int h, w;
    cin >> h >> w;
    vector<vector<int>> suml, sumr, sumu, sumd;
    suml.assign(h, vector<int>(w));
    sumr.assign(h, vector<int>(w));
    sumu.assign(h, vector<int>(w));
    sumd.assign(h, vector<int>(w));

    vector<string> s(h);
    rep(i, h) cin >> s[i];
    // lu
    rep(i, h) rep(j, w)
    {
        if (s[i][j] == '#')
        {
            suml[i][j] = 0;
            sumu[i][j] = 0;
        }
        else
        {
            if (j == 0)
                suml[i][j] = 1;
            else
                suml[i][j] = suml[i][j - 1] + 1;
            if (i == 0)
                sumu[i][j] = 1;
            else
                sumu[i][j] = sumu[i - 1][j] + 1;
        }
    }
    // rd
    for (int i = h - 1; i >= 0; --i)
        for (int j = w - 1; j >= 0; --j)
        {
            if (s[i][j] == '#')
            {
                sumr[i][j] = 0;
                sumd[i][j] = 0;
            }
            else
            {
                if (j == w - 1)
                    sumr[i][j] = 1;
                else
                    sumr[i][j] = sumr[i][j + 1] + 1;
                if (i == h - 1)
                    sumd[i][j] = 1;
                else
                    sumd[i][j] = sumd[i + 1][j] + 1;
            }
        }

    int ans = 1;
    rep(i, h) rep(j, w)
        ans = max(ans, suml[i][j] + sumr[i][j] + sumu[i][j] + sumd[i][j] - 3);
    cout << ans << endl;
}