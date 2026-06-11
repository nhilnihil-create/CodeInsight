#include <iostream>
#include <cmath>
using namespace std;

double minkowski(int* x, int* y, int n, int p) {
    double d = 0.0;
    for (int i = 0; i < n; i++) d += pow(abs(x[i] - y[i]), p);
    return pow(d, 1.0 / p);
}

int minkowski_infinite(int* x, int* y, int n) {
    int max = -1;
    for (int i = 0; i < n; i++) max = fmax(max, abs(x[i] - y[i]));
    return max;
}

int main(void){
    int n;
    cin >> n;

    int x[100], y[100];
    for (int i = 0; i < n; i++) cin >> x[i];
    for (int i = 0; i < n; i++) cin >> y[i];

    cout.setf(ios::fixed , ios::floatfield);
    cout << minkowski(x, y, n, 1) << endl;
    cout << minkowski(x, y, n, 2) << endl;
    cout << minkowski(x, y, n, 3) << endl;
    cout << minkowski_infinite(x, y, n) << endl;

    return 0;
}