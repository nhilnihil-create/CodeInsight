#include <bits/stdc++.h>

using namespace std;

const int N = 2020;
const int Mod = 1e9 + 7;

int a[N];
int b[N];
int Dp[N][N];

void add_self(int& x, int y)
{
    if((x += y) >= Mod) x -= Mod;
}

int add(int x, int y)
{
    return add_self(x, y), x;
}

void sub_self(int& x, int y)
{
    if((x -= y) < 0)    x += Mod;
}

int sub(int x, int y)
{
    return sub_self(x, y), x;
}

int main()
{
    int n, m;   cin >> n >> m;

    for(int i = 1; i <= n; i++) scanf("%d", a + i);
    for(int j = 1; j <= m; j++) scanf("%d", b + j);

    for(int i = 0; i <= n; i++) Dp[i][0] = 1;
    for(int j = 0; j <= m; j++) Dp[0][j] = 1;

    for(int i = 1; i <= n; i++)
    {
        for(int j = 1; j <= m; j++)
        {
            Dp[i][j] = add(Dp[i - 1][j], Dp[i][j - 1]);

            if(a[i] != b[j])    sub_self(Dp[i][j], Dp[i - 1][j - 1]);
        }
    }

    cout << Dp[n][m] << endl;
}
