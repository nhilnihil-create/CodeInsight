#include<iostream>
#include<math.h>
#include<stdio.h>
using namespace std;

int main()
{
    int n;
    double x[100], y[100], sum1 = 0, sum2 = 0, sum3 = 0, max;
    double D[100];
    cin >> n;
    for (int i = 0; i<n; i++)cin >> x[i];
    for (int i = 0; i<n; i++)cin >> y[i];
    max = fabs(x[0] - y[0]);
    for (int i = 0; i < n; i++)
        D[i]=fabs(x[i] - y[i]);
    for (int i = 0; i<n; i++) {
        sum1 += D[i];
        sum2 += fabs(D[i]*D[i]);
        sum3 += fabs(D[i]*D[i]*D[i]);
        if (max<D[i])max = D[i];
    }
    printf("%.8f\n", sum1);
    printf("%.8f\n", sqrt(sum2));
    printf("%.8f\n", pow(sum3, 1.0 / 3.0));
    printf("%.8f\n", max);
    return 0;
}