#include <stdio.h>
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define min(a, b) ((a) < (b) ? (a) : (b))
#define INF 100100

int main(void)
{
    int ans = 0;

    int h, w;
    scanf("%d%d", &h, &w);

    int s[101][101];
    rep(i, h)
    {
        char tmp[100 + 1];
        scanf("%s", tmp);
        rep(j, w)
        {
            if (tmp[j % w] == '#')
                s[i][j] = 1;
            else
                s[i][j] = 0;
        }
    }
    /*
    rep(i, h)
    {
        rep(j, w)
        {
            printf("%d", s[i][j]);
        }
        printf("\n");
    }
*/
    int dp[101][101];
    rep(i, h)
        rep(j, w)
            dp[i][j] = INF;

    dp[0][0] = s[0][0];

    rep(i, h)
    {
        rep(j, w)
        {
            if (j != w - 1)
                if (s[i][j] == 0 && s[i][j + 1] == 1)
                    dp[i][j + 1] = min(dp[i][j + 1], dp[i][j] + s[i][j + 1]);
                else
                    dp[i][j + 1] = min(dp[i][j + 1], dp[i][j]);
            if (i != h - 1)
                if (s[i][j] == 0 && s[i + 1][j] == 1)
                    dp[i + 1][j] = min(dp[i + 1][j], dp[i][j] + s[i + 1][j]);
                else
                    dp[i + 1][j] = min(dp[i + 1][j], dp[i][j]);
        }
    }
/*
    rep(i, h)
    {
        rep(j, w)
        {
            printf("%d ", dp[i][j]);
        }
        printf("\n");
    }
*/

    ans = dp[h - 1][w - 1];
    printf("%d\n", ans);

    return 0;
}