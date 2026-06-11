/*氏名：保坂優介, 学籍番号：200441141
  概要：*/

#include<stdio.h>
#include<math.h>

int main(void)
{
    int i, j, k, n, x[100], y[100];
    double p[4] = { 0 };

    scanf("%d", &n);

    for (i = 0; i < n; i++)
    {
        scanf("%d", &x[i]);
    }

    for (i = 0; i < n; i++)
    {
        scanf("%d", &y[i]);
    }

    for (i = 0; i < n; i++)
    {

        p[0] = p[0] + fabs(x[i] - y[i]);

    }

    for (i = 0; i < n; i++)
    {
        p[1] = p[1] + pow(fabs(x[i] - y[i]),2);
    }

    p[1] = sqrt(p[1]);

    for (i = 0; i < n; i++)
    {
        p[2] = p[2] + pow(fabs(x[i] - y[i]),3);
    }

    p[2] = cbrt(p[2]);

    for (i = 0; i < n; i++)
    {
        p[3] = fmax(p[3], fabs(x[i] - y[i]));
    }

    for (i = 0; i < 4; i++)
    {
        printf("%f\n", p[i]);
    }

    return 0;
}
