#define _USE_MATH_DEFINES
#include <bits/stdc++.h>
using namespace std;

int main()
{
    int n = 0, i;
    while (cin >> n, n)
    {
        double sum = 0, a = 0, m;
        int s[n];
        for (i = 0; i < n; i++)
        {
            scanf("%d", &s[i]);
            sum += s[i];
        }
        m = sum / n;
        for (i = 0; i < n; i++)
        {
            a += (s[i] - m) * (s[i] - m);
        }
        a = sqrt(a / n);
        printf("%lf\n", a);
    }
}
