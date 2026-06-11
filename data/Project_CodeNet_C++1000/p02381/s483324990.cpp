#include <iostream>
#include <cmath>

using namespace std;

int main() {

    int n, A[1000];
    double sum, avg;

    while (true) {

        cin >> n;
        if (n == 0) break;

        for (int i = 0; i < n; ++i) cin >> A[i];

        sum = 0;
        for (int i = 0; i < n; ++i) sum += A[i];

        avg = sum / n;
        sum = 0;
        for (int i = 0; i < n; ++i) {
            sum += (avg - A[i]) * (avg - A[i]);
        }

        printf("%lf\n", sqrt(sum / n));
    }
}