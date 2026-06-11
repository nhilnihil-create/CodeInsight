#include <iostream>
#include <complex>
#include <cmath>
#include <iomanip>
#include <algorithm>
using namespace std;

int main(void)
{
    int n;
    double a[1000];
    while (cin >> n && n != 0) {
        for (int i = 0; i < n; ++i)
            cin >> a[i];
        double ave = std::accumulate(a, a + n, 0.0) / n;
        double dev = 0.0;
        for (int i = 0; i < n; ++i)
            dev += pow(a[i] - ave, 2.0);
        dev /= n;
        cout << fixed << setprecision(10) << sqrt(dev) << endl;
    }
    return 0;
}





