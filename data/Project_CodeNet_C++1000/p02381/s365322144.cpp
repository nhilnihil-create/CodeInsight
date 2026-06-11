#include <iostream>
#include <math.h>
#define PI 3.14159265
using namespace std;

int main() {
//    freopen("in.txt", "r", stdin);

    int n, arr[1002] = {0};
    double sum = 0, avg = 0, result;
    while (1) {
        cin >> n;
        if (n == 0) {return 0;}

        sum = 0;
        for (int i = 0; i < n; ++i) {
            cin >> arr[i];
            sum += arr[i];
        }
        avg = sum / n;

        sum = 0;
        for (int i = 0; i < n; ++i) {
            sum += pow(arr[i] - avg, 2);
        }
        result = sqrt(sum / n);

        printf("%.4lf\n", result);
    }
}