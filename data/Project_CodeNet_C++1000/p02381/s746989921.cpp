#include <iostream>
#include <math.h>
#include <iomanip>

using namespace std;


int main() {

    while (true) {

        double sum = 0;
        double ave;

        int n;
        cin >> n;
        if (n == 0) {
            break;
        }
        int s[n];
        for (int i = 0; i < n; i++) {
            cin >> s[i];
            sum += s[i];
        }

        ave = sum / n;
        sum = 0;

        for (int i = 0; i < n; i++) {
            sum += (s[i] - ave) * (s[i] - ave);
        }

        double a = sum / n;

        cout << fixed << setprecision(8) << sqrt(a) << "\n";
    }


}