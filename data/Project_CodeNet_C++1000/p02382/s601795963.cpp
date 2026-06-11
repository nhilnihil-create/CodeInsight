#include <iostream>
#include <math.h>
#include <iomanip>

using namespace std;

int main() {
    long x[100];
    long y[100];
    int n;
    cin >>n;

    for (int i = 0; i < n ; ++i) {
        cin >> x[i];
    }
    for (int i = 0; i <n ; ++i) {
        cin >> y[i];
    }

    //???????????????????????¢
    double d1 = 0;
    for (int i = 0; i < n ; ++i) {
        d1 += fabs (x[i] - y[i]);
    }

    //???????????????????????¢
    double d2 = 0;
    for (int i = 0; i < n ; ++i) {
        d2 += pow(x[i] - y[i],2.0);
    }
        d2 = sqrt (d2);

    //p=3
    double d3 = 0;
    for (int m = 0; m < n ; ++m) {
        d3 += pow(fabs(x[m]-y[m]),3.0);
    }
        d3 = cbrt(d3);

    //max
    double d4 = 0;
    for (int i1 = 0; i1 < n ; ++i1) {
        if (d4 <= fabs (x[i1] - y[i1])){
            d4 =  fabs (x[i1] - y[i1]);
        }
    }

    cout << fixed << setprecision(9) << d1 << endl;
    cout << fixed << setprecision(9) << d2 << endl;
    cout << fixed << setprecision(9) << d3 << endl;
    cout << fixed << setprecision(9) << d4 << endl;
    return 0;

}