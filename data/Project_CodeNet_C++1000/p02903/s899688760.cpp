#include <bits/stdc++.h>
const int N = 1e3+5;
int n, m, a, b, s[N][N];
int main()
{
    scanf("%d%d%d%d", &n, &m, &a, &b);
    for(int i = 1; i <= b; ++i) for(int j = 1; j <= a; ++j) s[i][j] = 1;
    for(int i = b+1; i <= n; ++i) for(int j = a+1; j <= m; ++j) s[i][j] = 1;
    for(int i = 1; i <= n; puts(""), ++i) for(int j = 1; j <= m; ++j) putchar(s[i][j]^48);
    return 0;
}