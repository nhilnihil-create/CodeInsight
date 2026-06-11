#include <cstdio>
#include <math.h>

int main()
{
    int n;
    int x[1001], y[1001];
    double D1 = 0, D2 = 0;
    long double D3;
    long int sum = 0;
    int a;
    double max = 0;
    scanf("%d", &n);
    for (int i = 0; i < n; i++)
    {
        scanf("%d", &x[i]);
    }
    for (int i = 0; i < n; i++)
    {
        scanf("%d", &y[i]);
    }
    for (int i = 0; i < n; i++)
    {
        D1 += fabs(x[i] - y[i]);
    }
    printf("%.6f\n", D1);
    for (int i = 0; i < n; i++)
    {
        sum += fabs(x[i] - y[i]) * fabs(x[i] - y[i]);
    }
    D2 = sqrt(sum);
    printf("%.6f\n", D2);
    sum = 0;
    for (int i = 0; i < n; i++)
    {
        sum += pow( fabs(x[i] - y[i]),double(3));
    }
    D3 = pow(double(sum), double(0.3333333333333333333333));
    printf("%.6Lf\n", D3);
    for (int i = 0; i < n; i++)
    {
        a = fabs(x[i] - y[i]);
        if (max < a)
        {
            max = a;
        }
    }
    printf("%.6f\n", max);
}
