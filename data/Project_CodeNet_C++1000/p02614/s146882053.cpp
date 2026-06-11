#include <bits/stdc++.h>
using namespace std;

int main()
{
    int H, W, K;
    cin >> H >> W >> K;

    vector<string> C_li(H);
    for (int i = 0; i < H; i++)
    {
        cin >> C_li[i];
    }

    int res = 0;
    for (int i = 0; i < (1 << H); i++)
    {
        for (int j = 0; j < (1 << W); j++)
        {
            int black = 0;
            for (int k = 0; k < H; k++)
            {
                for (int l = 0; l < W; l++)
                {
                    if (((i >> k) & 1) == 0 && ((j >> l) & 1) == 0 && C_li[k][l] == '#')
                    {
                        black++;
                    }
                }
            }
            if (black == K)
            {
                res++;
            }
        }
    }

    cout << res << endl;
}
