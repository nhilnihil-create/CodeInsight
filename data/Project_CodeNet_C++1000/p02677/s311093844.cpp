#include <bits/stdc++.h>
using namespace std;

int main(void)
{   
    long double pi = M_PI;
    long double A,B;
    long double H;
    long double M;

    cin >> A >> B >> H >> M;

    long double rad;

    rad = pi * 2 * ( (H* 60.0 + M) / (12.0 * 60.0) - M /60.0 ) ;
    long double XX = A*A + B*B - (long double)(2.0 * A*B * cos(rad));
    long double X = sqrt(XX);

    cout << fixed << setprecision(15) << X << endl;
}