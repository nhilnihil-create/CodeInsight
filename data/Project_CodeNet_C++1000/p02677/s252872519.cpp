#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define PI acos(-1)
#define dans(d) cout << std::fixed << std::setprecision(20) << d << endl;


int main()
{
    int a, b, h, m;
    scanf("%d%d%d%d", &a, &b, &h, &m);

    long double rad = PI * 2 * ((long double)h / 12.0 + ((long double)m / 60.0) / 12.0 - (long
                                double)m / 60.0);

    long double rsq = (long double)(a * a + b * b) - (long double)(2 * a *
                      b) * cosl(rad);

     dans(sqrt(rsq));

    return 0;
}


