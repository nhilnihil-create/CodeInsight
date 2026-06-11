#include <iostream>
#include <stdio.h>
#include <cmath>
#include <math.h>

using namespace std;
int n;
double Minkowski_dist (int x[], int y[], int p)
{
    double result = 0;
    for (int i = 0; i < n; i++)
        result += pow(abs(x[i] - y[i]), p);
    result = pow(result, 1.0 / p);
    return result;
}
double Minkowski_dist_inftly(int x[], int y[])
{
    double result = 0;
    double temp;
    for (int i = 0; i < n; i++)
    {
        temp = abs(x[i] - y[i]);
        if(temp > result)
            result = temp;
    }
    return result;
}
int main()
{
    cin >> n;
    int x[n], y[n];
    for (int i = 0; i < n; i++)
        cin >> x[i];
    for (int i = 0; i < n; i++)
        cin >> y[i];

    for (int i = 1; i <= 3; i++)
        printf("%.6f\n", Minkowski_dist(x, y, i));
    printf("%.6f\n", Minkowski_dist_inftly(x, y));
    return 0;
}

