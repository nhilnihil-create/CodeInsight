#include<iostream>
using namespace std;
#include<iomanip>
#include<cmath>

int main()
{
    int i, n;
    int x[100], y[100];
    double d1 = 0, d2 = 0, d3 = 0, d_inf = 0;

    cin >> n;
    for(i = 0; i < n; i++){ cin >> x[i]; }
    for(i = 0; i < n; i++){
        cin >> y[i];
        d1 = d1 + abs(x[i] - y[i]);
        d2 = d2 + pow(1.0 * (x[i] - y[i]), 2.0);
        d3 = d3 + pow(1.0 * abs(x[i] - y[i]), 3.0);
        if(d_inf < abs(x[i] - y[i])) d_inf = abs(x[i] - y[i]);
    }

    cout << fixed << setprecision(10) << endl;
    cout << d1 << endl << sqrt(d2) << endl;
    cout << pow(d3, 1.0 / 3) << endl << d_inf << endl;

    return 0;
}