#include <bits/stdc++.h>
using namespace std;
#define m_p make_pair
mt19937 rnd(chrono::steady_clock::now().time_since_epoch().count());
mt19937 rnf(2106);
const int N = 1000006;

int n;

int q(int x)
{
    int u = 2;
    int ans = 0;
    while (u <= x)
    {
        ans += (x / u);
        u *= 2;
    }
    return ans;
}

char b[N];
int solvv()
{
    int ans = 0;
    for (int i = 1; i <= n; ++i)
    {
        if (b[i] == 1 && q(n - 1) - q((n - 1) - (i - 1)) == q((i - 1)))
            ans ^= 1;
    }
    return ans;
}

char a[N];

/*int dp[N][N];

int solv0()
{
    for (int i = 1; i <= n; ++i)
        dp[1][i] = a[i];
    for (int i = 2; i <= n; ++i)
    {
        for (int j = 1; j <= n - i + 1; ++j)
            dp[i][j] = abs(dp[i - 1][j] - dp[i - 1][j + 1]);
    }
    for (int i = 1; i <= n; ++i)
    {
        for (int j = 0; j < i - 1; ++j)
            printf(" ");
        for (int j = 1; j <= n - i + 1; ++j)
            printf("%d ", dp[i][j]);
        printf("\n");
    }
    return dp[n][1];
}*/

int solv()
{
    for (int i = 1; i <= n; ++i)
    {
        if (a[i] == 1)
            b[i] = 1;
        else
            b[i] = 0;
    }
    if (solvv() == 1)
        return 1;
    bool z = false;
    for (int i = 1; i <= n; ++i)
    {
        if (a[i] == 1)
        {
            z = true;
            break;
        }
    }
    if (z)
        return 0;
    for (int i = 1; i <= n; ++i)
    {
        if (a[i] == 0)
            b[i] = 0;
        else
            b[i] = 1;
    }
    if (solvv() == 1)
        return 2;
    return 0;
}

int main()
{
    #ifdef SOMETHING
    freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);
    #endif // SOMETHING
    scanf("%d", &n);
    scanf(" %s", (a + 1));
    for (int i = 1; i <= n; ++i)
        a[i] -= '1';
    printf("%d\n", solv());
    return 0;
    while (1)
    {
        n = rnf() % 15 + 1;
        for (int i = 1; i <= n; ++i)
        {
            a[i] = rnf() % 3 + 1 + '0';
        }
    }
    return 0;
}

//while ((double)clock() / CLOCKS_PER_SEC <= 0.9){}
