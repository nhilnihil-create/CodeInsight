#include <bits/stdc++.h>
#include <iostream>
using namespace std;

int main()
{
    int a, b, x;
    cin >> a >> b >> x;
    double ad = (double) a;
    double bd = (double) b;
    double xd = (double) x;

    if( 2 * x >= a * a * b )
    {
        cout << std::fixed << std::setprecision(15) << atan2( 2 * bd - 2 * xd / ad / ad, ad ) * 180 / M_PI;
    }
    else
    {
        cout << std::fixed << std::setprecision(15) << atan2(bd, 2 * xd / ad / bd) * 180 / M_PI;
    }
}