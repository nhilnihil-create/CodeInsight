#include <iostream>
#include <cmath>
#include <cstdio>

using namespace std;

int main() {
    double n, s, m, sum = 0;
    while(1) {
        sum = 0;
        cin >> n;
        if(n == 0) break;
        double s[1000] = {};
        for(int i = 0; i < n; i++) {
            cin >> s[i];
        }
        for(int i = 0; i < n; i++) {
            sum += s[i];
        }
        m = sum/n;
        sum = 0;
        for(int i = 0; i < n; i++) {
            sum += (s[i] -m)*(s[i] -m);
        }
        printf("%.10lf\n", sqrt(sum/n));
    }
    return 0;
}
