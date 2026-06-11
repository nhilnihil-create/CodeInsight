#include <cstdio>
#include <cmath>
#include <algorithm>

using namespace std;

int main()
{
    int n;
    double x[100], y[100], p[4]={0};
    scanf("%d", &n);
    for (int i=0; i<n; i++) scanf("%lf", &x[i]);
    for (int i=0; i<n; i++) scanf("%lf", &y[i]);
    for (int i=0; i<n; i++)
    {
        p[0]+=abs(x[i]-y[i]);
        p[1]+=pow(abs(x[i]-y[i]), 2);
        p[2]+=pow(abs(x[i]-y[i]), 3);
        p[3]=max(p[3], abs(x[i]-y[i]));
    }
    printf("%.10f\n%.10f\n%.10f\n%.10f\n", p[0], sqrt(p[1]), cbrt(p[2]), p[3]);
    return 0;
}

