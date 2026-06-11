#include <bits/stdc++.h>
using namespace std;
#define m_p make_pair
mt19937 rnd(chrono::steady_clock::now().time_since_epoch().count());
mt19937 rnf(2106);
const int N = 102, INF = 1000000009;

int n, m;
char a[N][N];

int dp[N][N];

void solv()
{
    scanf("%d%d", &n, &m);
    for (int i = 1; i <= n; ++i)
        scanf(" %s", (a[i] + 1));
    for (int i = n; i >= 1; --i)
    {
        for (int j = m; j >= 1; --j)
        {
            if (a[i][j] == '#')
            {
                if (i == n && j == m)
                {
                    dp[i][j] = 1;
                }
                else if (i == n)
                {
                    if (a[i][j + 1] == '#')
                        dp[i][j] = dp[i][j + 1];
                    else
                        dp[i][j] = dp[i][j + 1] + 1;
                }
                else if (j == m)
                {
                    if (a[i + 1][j] == '#')
                        dp[i][j] = dp[i + 1][j];
                    else
                        dp[i][j] = dp[i + 1][j] + 1;
                }
                else
                {
                    dp[i][j] = INF;
                    if (a[i + 1][j] == '#')
                        dp[i][j] = min(dp[i][j], dp[i + 1][j]);
                    else
                        dp[i][j] = min(dp[i][j], dp[i + 1][j] + 1);
                    if (a[i][j + 1] == '#')
                        dp[i][j] = min(dp[i][j], dp[i][j + 1]);
                    else
                        dp[i][j] = min(dp[i][j], dp[i][j + 1] + 1);
                }
            }
            else
            {
                if (i == n && j == m)
                {
                    dp[i][j] = 0;
                }
                else if (i == n)
                {
                    dp[i][j] = dp[i][j + 1];
                }
                else if (j == m)
                {
                    dp[i][j] = dp[i + 1][j];
                }
                else
                {
                    dp[i][j] = INF;
                    dp[i][j] = min(dp[i][j], dp[i + 1][j]);
                    dp[i][j] = min(dp[i][j], dp[i][j + 1]);
                }
            }
        }
    }
    printf("%d\n", dp[1][1]);
}

int main()
{
    #ifdef SOMETHING
    freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);
    #endif // SOMETHING
    solv();
    return 0;
}

//while ((double)clock() / CLOCKS_PER_SEC <= 0.9){}
