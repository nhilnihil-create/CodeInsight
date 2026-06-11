#include <iostream>
#include <cmath>
#include <iomanip>
using namespace std;
int main(void){
    int n;
    cin >> n;
    int x[n];
    int y[n];
    int sum1 = 0;
    int sum2 = 0;
    long sum3 = 0;
    int max = 0;
    for (int i = 0; i < n; i++) {
        cin >> x[i];
    }
    for (int i = 0; i < n; i++) {
        cin >> y[i];
    }
    for (int i = 0; i < n; i++) {
        int d = abs(x[i] - y[i]);
        sum1 += d;
        sum2 += d * d;
        sum3 += d * d * d;
        if (d > max) max = d;
    }
    cout << fixed << setprecision(8);
    cout << sum1 << endl;
    cout << pow(sum2, 1 / 2.0) << endl;
    cout << pow(sum3, 1 / 3.0) << endl;
    cout << max << endl;
}