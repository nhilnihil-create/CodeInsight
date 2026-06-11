#define _USE_MATH_DEFINES
#include <bits/stdc++.h>
using namespace std;

double mDistance(double xyDif[], int n, int p)
{
    double ans = 0;
    for (int i = 0; i < n; i++)
        ans += pow(xyDif[i], p);
    if (p == 2)
        ans = sqrt(ans);
    else if (p == 3)
        ans = cbrt(ans);
    return ans;
}

int main()
{
    int n, i;
    scanf("%d", &n);
    int x[n], y[n];
    double xyDif[n], ans[4] = {};
    for (i = 0; i < n; i++)
        scanf("%d", &x[i]);
    for (i = 0; i < n; i++)
    {
        scanf("%d", &y[i]);
        xyDif[i] = fabs(x[i] - y[i]);
    }

    for (i = 0; i < 3; i++)
        ans[i] = mDistance(xyDif, n, i + 1);
    for (i = 0; i < n; i++)
        ans[3] = max(ans[3], xyDif[i]);

    for (i = 0; i < 4; i++)
        printf("%lf\n", ans[i]);
}

