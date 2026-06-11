#include <iostream>
#include <math.h>
#include <iomanip>

using namespace std;

int main() {
    long n;
    long s[1000]={0};


    while(1){
        cin >> n;
        if (n==0)break;
        double sum = 0;
        for (int i = 0; i < n; ++i) {
            cin >> s[i];
            sum += s[i];
        }

        //ave
        double ave = sum / n;

        //Dispersion
        double alpha = 0;
        for (int i = 0; i < n; ++i) {
            alpha += (s[i] - ave) * (s[i] - ave) / n;
        }
        cout << fixed << setprecision(9) << sqrt(alpha) << endl;
    }
     return 0;
}