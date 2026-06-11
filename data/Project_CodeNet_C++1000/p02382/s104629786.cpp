#include<iostream>
#include <math.h>
#include <iomanip>
#include <stdlib.h>

using namespace std;

int main() {
    int n;
    cin >> n;
    int arrayX[n] = {};
    int arrayY[n] = {};
    for (int i = 0; i < n; i++) {
        cin >> arrayX[i];
    }
    for (int i = 0; i < n; i++) {
        cin >> arrayY[i];
    }
    for (int x = 1; x < 5; x++) {
        double sum = 0;
        if (x == 4) {
            double lowest = 0;
            for (int i = 0; i < n; i++) {
                if (abs(arrayX[i] - arrayY[i]) > lowest) {
                    lowest = abs(arrayX[i] - arrayY[i]);
                }
            }
            cout << fixed << setprecision(10) << lowest << endl;

        } else {
            for (int i = 0; i < n; i++) {
                sum += pow(abs(arrayX[i] - arrayY[i]), x);
            }
            sum = pow(sum, (1.0 / x));
            cout << fixed << setprecision(10) << sum << endl;
        }

    }
}
