#include <bits/stdc++.h>
using namespace std;

int main()
{
    int a, b, h, m;

    double result, h_degrees, m_degrees;

    cin >> a >> b >> h >> m;

    m_degrees = (m/60.0)*360.0;
    h_degrees  = (h/12.0)*360 + (m/60.0)*30;

    result = a*a + b*b - 2*a*b*cos(abs(m_degrees - h_degrees)*(M_PI/180));

    printf("%.10lf\n",sqrt(result));
    //cout << (double)sqrt(result) << endl;
    return 0;
}