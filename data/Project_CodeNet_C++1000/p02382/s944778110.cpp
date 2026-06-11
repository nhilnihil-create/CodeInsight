#include<iostream>
#include<iomanip>
#include<cmath>
using namespace std;

int main()
{
    int num;

    cin >> num;

    int x[num], y[num];
    double d1 = 0, d2 = 0, d3 = 0, df = 0;

    for( int i = 0; i < num; i++ )
        cin >> x[i];
    for( int i = 0; i < num; i++ )
        cin >> y[i];

    for( int i = 0; i < num; i++ )
        d1 += fabs( x[i] - y[i] );

    for( int i = 0; i < num; i++ )
        d2 += pow( fabs( ( x[i] - y[i] ) ), 2 );
    d2 = sqrt(d2);
    
    for( int i = 0; i < num; i++ )
        d3 += pow( fabs( x[i] - y[i] ), 3 );
    d3  = pow( d3, 1.0 / 3.0 );

    for( int i = 0; i < num; i++ )
    {
        if( df < fabs( x[i] - y[i] ) )
            df = fabs( x[i] - y[i] );
    }

    cout << fixed;
    cout << setprecision(10) << d1 << endl;
    cout << d2 << endl;
    cout << d3 << endl;
    cout << df << endl;

    return 0;
}
