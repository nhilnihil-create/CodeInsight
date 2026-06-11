#include <iostream>
#include <cstdio>
#include <algorithm>
#include <vector>

#define rep0(i, n) for (i = 0; i < n; i++)
#define rep(s, i, n) for (i = s; i < n; i++)
using namespace std;
char s[10][10];

int main()
{
    int n, m, k, S, ans = 0;
    scanf("%d%d%d", &n, &m, &k); S = 1 << (n + m);
    for (int i = 0; i < n; i++)
        scanf("%s", s[i]);
    for (int i = 0; i < S; i++)
    {
        int w = 0;
        for (int j = 0; j < n; j++)
            for (int l = 0; l < m; l++)
                if (s[j][l] == '#' && (i & (1 << j)) == 0 && (i & (1 << (l + n))) == 0)
                    w++;
        ans += w == k;
    }
    printf("%d\n", ans);
    return 0;
}