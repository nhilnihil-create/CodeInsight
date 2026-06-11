#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
#include <math.h>
using namespace std;
#define rep(i,n) for(int i = 0; i < (int)(n); i++)
#define invrep(i,n) for(int i = (int)(n); i > 0; i++)
using ll = long long;

#define PI 3.14159265358979323846264338327950L

int main() {
    float a, b, h, m;
    cin >> a >> b >> h >> m;

    // if (h == 0) h = 12;
    // if (m == 0) m = 60;

    // float h_ang = (h / 12) * 360;
    // float m_ang = (m / 60) * 360;

    // float c_ang = abs(h_ang - m_ang);

    long double rad = PI * 2 * ((long double)h / 12.0 + ((long double)m / 60.0) / 12.0 - (long double)m / 60.0);

    // cout << rad << endl;
    // cout << pow(pow(a, 2) + pow(b, 2) - (2 * a * b * cos(rad)), 0.5) << endl;
    long double rsq = pow(pow(a, 2) + pow(b, 2) - (2 * a * b * cos(rad)), 0.5);
    printf("%20.20Lf\n", rsq);
    return 0;
}