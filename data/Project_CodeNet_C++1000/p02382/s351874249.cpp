#include <iostream>
#include <cmath>
#include <iomanip>
using namespace std;
int main(void){
    // Here your code !
    int n;
    cin >> n;
    int x[n], y[n];
    for(int i=0;i<n;i++) {
        cin >> x[i];
    }
    for(int i=0;i<n;i++) {
        cin >> y[i];
    }
    double d1 = 0, d2 = 0, d3 = 0, d = 0;
    for(int i=0;i<n;i++) {
        d1 = d1 + abs(x[i] - y[i]);
        d2 = d2 + pow(x[i] - y[i], 2);
        d3 = d3 + pow(abs(x[i] - y[i]), 3);
        d = fmax(d, abs(x[i] - y[i]));
    }
    d2 = sqrt(d2);
    d3 = cbrt(d3);
    cout << fixed
         << setprecision(10)
         << d1 << endl
         << d2 << endl
         << d3 << endl
         << d << endl;
}