#include<iostream>
#include<cmath>
#include<cstdio>

using namespace std;

int main(int argc, char const *argv[])
{
    int n;
    double x[100]={},y[100]={};
    double d1=0,d2=0,d3=0,dinf=0;

    cin >> n;
    for (int i = 0; i < n; ++i)
    {
        cin >> x[i];
    }
    for (int i = 0; i < n; ++i)
    {
        cin >> y[i];
    }

    for (int i = 0; i < n; ++i)
    {
        d1 += fabs(x[i]-y[i]);
        d2 += (x[i]-y[i])*(x[i]-y[i]);
        d3 += fabs((x[i]-y[i])*(x[i]-y[i])*(x[i]-y[i]));
        if(dinf < fabs(x[i]-y[i])) dinf = fabs(x[i]-y[i]);
    }
    d2 = sqrt(d2);
    d3 = pow(d3,(1.0/3));
    printf("%lf\n%lf\n%lf\n%lf\n", d1,d2,d3,dinf);

    return 0;
}