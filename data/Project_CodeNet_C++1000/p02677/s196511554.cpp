#include <iostream>
#include <stdio.h>
#include <cmath>

using namespace std;

int main(){
    int a, b, h, m;
    double dist, h_deg, m_deg, deg;

    cin >> a >> b >> h >> m;

    h_deg = h * 30.0 + m * 0.5;
    m_deg = m * 6.0;
    dist = sqrt((double)(a*a + b*b) - (double)(2*a*b*cos(abs(h_deg - m_deg) * M_PI / 180)));

    printf("%.10f\n", dist);

    return 0;
}