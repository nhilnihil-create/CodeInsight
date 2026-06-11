#include<iostream>
#include<iomanip>
#include<cmath>
using namespace std;

int main()
{
    int a, b;
    double c;
    double rad, pi = acos(-1);
    double S, L, h;

    cin >> a >> b >> rad;

    if( rad < 90 )
    {
        if( a == b )
            c = a;
        else if( a > b )
            c = sqrt( pow( a*sin(rad*pi/180), 2 ) + pow( b-a*cos(rad*pi/180), 2 ) );
        else
            c = sqrt( pow( b*sin(rad*pi/180), 2 ) + pow( a-b*cos(rad*pi/180), 2 ) );
        S = a * sin(rad*pi/180) * b / 2;
        L = a + b + c;
        h = b * sin(rad*pi/180);
    }
    else if( rad > 90 )
    {
        if ( a > b )
        {
            c = sqrt( pow(a*sin((180-rad)*pi/180),2) + pow( b+a*cos((180-rad)*pi/180),2 ) );
            S = b*a*sin((180-rad)*pi/180)/2;
            h = b*sin((180-rad)*pi/180);
        }
        else
        {
            c = sqrt( pow(b*sin((180-rad)*pi/180),2) + pow( a+b*cos((180-rad)*pi/180),2 ) );
            S = a*b*sin((180-rad)*pi/180)/2;
            h = a*sin((180-rad)*pi/180);
        }
        L = a + b + c;
    }
    else
    {
        if( a > b )
            h = b;
        else
            h = a;
        c = sqrt(a*a+b*b);
        S = a * b / 2;
        L = a + b + c;
    }

    cout << fixed;
    cout << setprecision(11) << S << endl;
    cout << L << endl;
    cout << h << endl;

    return 0;
}
