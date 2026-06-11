#include <iostream>
#include <string>
#include <cmath>
#include <iomanip>
using namespace std;


int main() {
    int i, j, num, start, end, c;
    double a, b, rad, x[100], y[100], ab[100], mean, dev, d_1=0.0, d_2=0.0, d_3=0.0, d_inf=0.0;

    cin >> num;
    for(i=0;i<num;i++){
        cin >> x[i];
    }
    for(i=0;i<num;i++){
        cin >> y[i];
    }
    for(i=0;i<num;i++){
        ab[i] = abs(x[i] - y[i]);
    }
    for(i=0;i<num;i++){
        d_1 = d_1 + ab[i];
        d_2 = d_2 + ab[i]*ab[i];
        d_3 = d_3 + ab[i]*ab[i]*ab[i];
        if(d_inf < ab[i]){
            d_inf = ab[i];
        }
    }

    cout << fixed <<setprecision(10) << d_1 << endl;
    cout << fixed <<setprecision(10) << sqrt(d_2) << endl;
    cout << fixed <<setprecision(10) << pow(d_3, 1.0/3.0) << endl;
    cout << fixed <<setprecision(10) << d_inf << endl;
    return 0;
}

