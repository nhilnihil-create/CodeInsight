#include <cmath>
#include <cstdio>
#include <iostream>
using namespace std;

int n;
void make(double x1, double y1, double x2, double y2, int m);

int main()
{
    cin >> n;
    make(0.000000, 0.000000, 100.000000, 0.000000, n);
    //cout << 100.000000 << " " << 0.000000 << endl;
    printf("%f %f\n", 100.000000, 0.000000);
}

void make(double x1, double y1, double x2, double y2, int m)
{
    if (m == 0) {
        printf("%f %f\n", x1, y1);
    } else {
        double dx = x2 - x1;
        double dy = y2 - y1;
        double px1 = x1 + dx / 3.0;
        double py1 = y1 + dy / 3.0;
        double px2 = x1 + dx / 2.0 - (sqrt(3.0) / 6.0) * dy /*/ sqrt(dx * dx + dy * dy)*/;
        double py2 = y1 + dy / 2.0 + (sqrt(3.0) / 6.0) * dx /*/ sqrt(dx * dx + dy * dy)*/;
        double px3 = x1 + dx * 2.0 / 3.0;
        double py3 = y1 + dy * 2.0 / 3.0;
        m--;
        make(x1, y1, px1, py1, m);
        make(px1, py1, px2, py2, m);
        make(px2, py2, px3, py3, m);
        make(px3, py3, x2, y2, m);
    }
}
