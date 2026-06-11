#include <cstdio>
#include <math.h>

int main()
{
    while (1)
    {
        int s[1001];
        double n, m;
        double a;
        int sum = 0;
        double sum1 = 0;
        scanf("%lf", &n);
        if (n == 0)
        {
            break;
        }
        for (int i = 0; i < n; i++)
        {
            scanf("%d", &s[i]);
            sum += s[i];
        }
        m = sum / n;
        for (int i = 0; i < n; i++)
        {
            sum1 += (s[i] - m) * (s[i] - m);
        }
        a = sqrt(sum1 / n);
        printf("%.8f\n", a);
    }
}
