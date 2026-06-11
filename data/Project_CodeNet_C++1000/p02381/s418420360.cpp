#include <iostream>
#include <cmath>
using namespace std;

int main(void) {
    int n;
    double var, mean, sum, sd;
    int s[1000];
    while (1) {
        cin >> n;
        if (n == 0) break;
        sum = 0;
        for (int i = 0; i < n; i++) {
            cin >> s[i];
            sum += s[i];
        }
        mean = double(sum) / n;
        var = 0;
        for (int i = 0; i < n; i++) {
            var += pow(s[i] - mean, 2);
        }
        var /= n;
        cout << fixed << sqrt(var) << endl;
    }
    return 0;
}