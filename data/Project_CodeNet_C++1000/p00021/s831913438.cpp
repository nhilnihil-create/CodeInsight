#include <iostream>
#include <complex>
#include <cmath>
#include <cstdio>
using namespace std;
typedef complex<double> xy_t;
const double eps = 1e-11;

double dot_product(xy_t a, xy_t b) { return (conj(a) * b).real(); }
double cross_product(xy_t a, xy_t b) { return (conj(a) * b).imag(); }
xy_t projection(xy_t p, xy_t b) { return b * dot_product(p, b) / norm(b); }

int main()
{
    int n = 0;
    double x, y;
    xy_t P[4];
    double sum = 0.0;
    cin >> n;
    bool answer[n] = {};
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < 4; j++)
        {
            cin >> x >> y;
            P[j] = xy_t(x, y);
        }
        xy_t a[2] = {P[1] - P[0], P[3] - P[2]};
        if (abs(cross_product(a[0], a[1])) < eps)
        {
            answer[i] = 1;
        }
    }
    for (int i = 0; i < n; i++)
    {
        if (answer[i])
        {
            cout << "YES" << endl;
        }
        else
        {
            cout << "NO" << endl;
        }
    }
    return 0;
}

