#include <iostream>
#include <cmath>
using namespace std;
int main(void){
    while (1) {
        int n;
        cin >> n;
        if (n == 0) break;
        int s[n];
        for (int i = 0; i < n; i++) {
            cin >> s[i];
        }
        double sum = 0;
        for (int i = 0; i < n; i++) {
            sum += s[i];
        }
        double ave = sum / n;
        sum = 0;
        for (int i = 0; i < n; i++) {
            sum += (s[i] - ave) * (s[i] - ave);
        }
        double dist = sum / n;
        cout << sqrt(dist) << endl;
    }
}