#include<iostream>
using namespace std;
#include<iomanip>
#include<cmath>

#define MAX 5000

void show(double* x, double* y, int size)
{
    int i;
    cout << fixed << setprecision(10);
    for(i = 0; i < size; i++){
        cout << x[i] << " " << y[i] << endl;
    }
}

void Kochcurve(double* x, double* y, int left, int right)
{
    int d = (right - left) / 4;
    if(d < 1) return;

    int m;
    double x1, x2, y1, y2;

    m = (left + right) / 2;
    x1 = x[left]; x2 = x[right];
    y1 = y[left]; y2 = y[right];

    x[left + d] = (2 * x1 + x2) / 3;
    y[left + d] = (2 * y1 + y2) / 3;

    x[m] = (x1 + x2) / 2 - (y2 - y1) * sqrt(3 * 1.0) / 6;
    y[m] = (y1 + y2) / 2 + (x2 - x1) * sqrt(3 * 1.0) / 6;
 
    x[right - d] = (x1 + 2 * x2) / 3;
    y[right - d] = (y1 + 2 * y2) / 3;

    Kochcurve(x, y, left, left + d);
    Kochcurve(x, y, left + d, m);
    Kochcurve(x, y, m, right - d);
    Kochcurve(x, y, right - d, right);

    return;
}

int main()
{
    double x[MAX], y[MAX];
    int i, n, R;
    cin >> n;
    R = 1;
    for(i = 0; i < n; i++) R = R * 4;

    x[0] = 0;
    y[0] = 0;
    x[R] = 100 * 1.0;
    y[R] = 0;

    Kochcurve(x, y, 0, R);

    show(x, y, R + 1);

    return 0;
}