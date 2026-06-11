#include<iostream>
using namespace std;
#include<cmath>
#include<math.h>

int main() {
        double a, b, angle, rad, h, area, c, pi;
        cin >> a >> b >> angle;
        rad = angle * (M_PI / 180);
        h = b*sin(rad);
        c = sqrt(pow(a, 2) + pow(b, 2) - 2 * a * b * cos(rad));
        area = ((a * b) / 2) * sin(rad);
        cout << fixed;
        cout << area << endl;
        cout << a + b + c << endl;
        cout << h << endl;
}