#include <iostream>
#include <cstdio>
#include <cmath>
using namespace std;

int main(void) {
    int n;
    int x[1000] = {};
    int y[1000] = {};
    double a;
    
    cin >> n;
    
    for(int i = 0; i < n; ++i) {
        cin >> x[i];
    }
    for(int i = 0; i < n; ++i) {
        cin >> y[i];
    }
    
    for(int i = 1; i <= 3; ++i) {
        a = 0;
        for(int j = 0; j < n; ++j) {
            a += pow(abs(x[j] - y[j]), i);
        }
        a = pow(a, (double)1 / i);
        printf("%lf\n", a);
    }
    a = 0;
    for(int i = 0; i < n; ++i) {
        if(a < abs(x[i] - y[i])) {
            a =  abs(x[i] - y[i]);
        }
    }
    printf("%lf\n", a);
    
    return 0;
    
}
