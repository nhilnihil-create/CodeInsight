#include <bits/stdc++.h>
using namespace std ;

//variable
double a = 0 ; //length a
double b = 0 ; //length b
double c = 0 ; //length c
double D = 0 ; //degree
double R = 0 ; //radian
double S = 0 ; //area of triangle
double L = 0 ; //length of the lap
double h = 0 ; //height

int main()
{
    cin >> a >> b >> D ;

    R = D * M_PI / 180.0 ;
    c = sqrt( pow( a ,2 ) + pow( b ,2 ) - ( ( 2 * a * b ) * cos( R ) ) ) ;
    L = a + b + c ;
    h = b * sin( R ) ;
    S = ( 1.0 / 2.0 ) * a * h ;

    cout << fixed << setprecision(5) << S << endl << L << endl << h << endl ;
    return 0 ;
}