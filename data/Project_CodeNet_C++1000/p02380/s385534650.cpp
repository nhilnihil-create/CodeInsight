#include<bits/stdc++.h>
using std::cout;
using std::cin;
using std::endl;

int main()
{
    double s, l, h, a, b, c, rad;
    int deg;

    cin >> a >> b >> deg;
    rad = deg * M_PI / 180;

    s = a * b * sin(rad)/2;
    c = sqrt(pow(a, 2) + pow(b, 2) - 2*a*b*cos(rad));
    l = a + b + c;
    h = 2 * s / a;


    cout << std::fixed << std::setprecision(8)
         << s << '\n' 
         << l << '\n'
         << h << endl;

    return 0;
}
