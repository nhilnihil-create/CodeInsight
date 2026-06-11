#include <iostream>
#include <cmath>
#include <cstdio>
using namespace std;

int main()
{
    int n,p;
    double d;
    cin >> n;
    int x[n],y[n];
    
    for(int i=0; i<n; i++)
        cin >> x[i];
    for(int i=0; i<n; i++)
        cin >> y[i];
    
    for( p = 1; p < 4; ++p ){
        d = 0.0;
        for(int i = 0; i < n; ++i )
            d += pow(abs(x[i] - y[i]), p);
        d = pow(d, 1.0/p);
        printf("%.6lf\n", d);
    }
    
    d = 0;
    for(int i = 0; i < n; ++i ){
        double tmp = (abs(x[i] - y[i]));
        d = d < tmp ? tmp : d;
    }
    
    printf("%.6f\n",d);
    
    return 0;
}
