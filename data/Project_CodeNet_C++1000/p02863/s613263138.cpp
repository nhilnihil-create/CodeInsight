#include <bits/stdc++.h>
using namespace std;
const int M = 6010;
int dp[M];
struct node
{
    int a, b;
}p[M];
bool cmp(node x, node y)
{
    return x.a < y.a;
}
int main()
{
    int n, t;
    scanf("%d%d", &n, &t);
    int w = 6000;
    for(int i = 1; i <= n; i++) scanf("%d%d", &p[i].a, &p[i].b);
    sort(p + 1, p + n + 1, cmp);
    for(int i = 1; i <= w; i++) dp[i] = -1;
    for(int i = 1; i <= n; i++)
    {
        //printf("i = %d\n", i);
        for(int j = w; j >= p[i].a; j--)
        {
            if(j - p[i].a < t && dp[j - p[i].a] != -1)
            {

                dp[j] = max(dp[j], dp[j - p[i].a] + p[i].b);//printf("j = %d %d\n", j, dp[j]);
            }
        }
    }
    int maxn = 0;
    for(int i = 1; i <= w; i++)
    {
        maxn = max(maxn, dp[i]);//printf("i = %d %d\n", i, dp[i]);
    }
    printf("%d\n", maxn);
    return 0;
}
