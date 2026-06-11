#include <iostream>
#include <math.h>
#include <iomanip>

using namespace std;


int main() {
    int n;
    cin >> n;
    int x[n];
    for (int i = 0; i < n; i++) {
        cin >> x[i];
    }
    int y[n];
    for (int i = 0; i < n; i++) {
        cin >> y[i];
    }

    double sum = 0;
    for (int i = 0; i < n; i++) {
        sum += abs(x[i] - y[i]);
    }
    cout << fixed << setprecision(8) << sum << "\n";

    sum = 0;
    for (int i = 0; i < n; i++) {
        sum += pow(abs(x[i] - y[i]), 2);
    }
    cout << fixed << setprecision(8) << sqrt(sum) << "\n";

    sum = 0;
    for (int i = 0; i < n; i++) {
        sum += pow(abs(x[i] - y[i]), 3);
    }
    cout << fixed << setprecision(8) << cbrt(sum) << "\n";

    double max = abs(x[0] - y[0]);
    for (int i = 1; i < n; i++) {
        if (max < abs(x[i] - y[i])) {
            max = abs(x[i] - y[i]);
        }
    }
    cout << fixed << setprecision(8) << max << "\n";


}